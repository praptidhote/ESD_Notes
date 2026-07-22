#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

#define MAX_BUF_SIZE 32

static char buf[MAX_BUF_SIZE]; 
static dev_t devno; 
static struct class *pclass;
static struct cdev pchar_cdev; 

static int pchar_open(struct inode *pinode, struct file *pfile);
static int pchar_close(struct inode *pinode, struct file *pfile);
static ssize_t pchar_write(struct file *pfile, const char __user *pubuf, size_t bufsize, loff_t *poffset);
static ssize_t pchar_read(struct file *pfile, char __user *pubuf, size_t bufsize, loff_t *poffset);

static struct file_operations pchar_fops = 
{
    .owner = THIS_MODULE,
    .open = pchar_open,
    .release = pchar_close,
    .read = pchar_read,
    .write = pchar_write
};

static int __init pchar_init(void) {
    int ret;
    struct device *pdevice;
    pr_info("pchar: pchar_init() called.\n");
   
    ret = alloc_chrdev_region(&devno, 0, 1, "pchar");
    if (ret < 0) {
        pr_err("pchar: Failed to allocate chrdev region\n");
        return ret;
    }
    pr_info("pchar: device number = %d/%d.\n", MAJOR(devno), MINOR(devno));
   
    pclass = class_create("pchar_class");
    if (IS_ERR(pclass)) {
        unregister_chrdev_region(devno, 1);
        return PTR_ERR(pclass);
    }
    
    pdevice = device_create(pclass, NULL, devno, NULL, "pchar%d", 0);
    if (IS_ERR(pdevice)) {
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);
        return PTR_ERR(pdevice);
    }
  
    cdev_init(&pchar_cdev, &pchar_fops);
    pchar_cdev.owner = THIS_MODULE;
    ret = cdev_add(&pchar_cdev, devno, 1);
    if (ret < 0) {
        device_destroy(pclass, devno);
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);
        return ret;
    }
    
    pr_info("pchar: Driver loaded successfully\n");
    return 0;
}

static void __exit pchar_exit(void) {
    pr_info("pchar: pchar_exit() called.\n");
  
    cdev_del(&pchar_cdev);
    device_destroy(pclass, devno);
    class_destroy(pclass);
    unregister_chrdev_region(devno, 1);
    
    pr_info("pchar: Driver unloaded successfully\n");
}

int pchar_open(struct inode *pinode, struct file *pfile) {
    pr_info("pchar: pchar_open() called.\n");
    return 0;
}

int pchar_close(struct inode *pinode, struct file *pfile) {
    pr_info("pchar: pchar_close() called.\n");
    return 0;
}

ssize_t pchar_write(struct file *pfile, const char __user *pubuf, size_t bufsize, loff_t *poffset) {
    size_t bytes_to_write;
    size_t bytes_failed;

    pr_info("pchar: pchar_write() called.\n");

    if (*poffset >= MAX_BUF_SIZE)
        return -ENOSPC;

    bytes_to_write = bufsize;
    if (bytes_to_write > (MAX_BUF_SIZE - *poffset))
        bytes_to_write = MAX_BUF_SIZE - *poffset;

    bytes_failed = copy_from_user(buf + *poffset, pubuf, bytes_to_write);
    if (bytes_failed == bytes_to_write)
        return -EFAULT;

    bytes_to_write -= bytes_failed;
    *poffset += bytes_to_write;

    return bytes_to_write;
}

ssize_t pchar_read(struct file *pfile, char __user *pubuf, size_t bufsize, loff_t *poffset) {
    size_t bytes_to_read;
    size_t bytes_failed;

    pr_info("pchar: pchar_read() called.\n");

    if (*poffset >= MAX_BUF_SIZE)
        return 0;

    bytes_to_read = bufsize;
    if (bytes_to_read > (MAX_BUF_SIZE - *poffset))
        bytes_to_read = MAX_BUF_SIZE - *poffset;

    bytes_failed = copy_to_user(pubuf, buf + *poffset, bytes_to_read);
    if (bytes_failed == bytes_to_read)
        return -EFAULT;

    bytes_to_read -= bytes_failed;
    *poffset += bytes_to_read;

    return bytes_to_read;
}

module_init(pchar_init);
module_exit(pchar_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Prapti Dhote <praptidhote6509@gmail.com>");
MODULE_DESCRIPTION("Pseudo char device driver");
