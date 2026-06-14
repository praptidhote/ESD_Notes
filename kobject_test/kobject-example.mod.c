#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8c8569cb, "kstrtoint" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2cbe8aca, "kernel_kobj" },
	{ 0xf18d53d9, "kobject_create_and_add" },
	{ 0x153e1966, "sysfs_create_group" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x219950d3, "kobject_put" },
	{ 0x7bec7de9, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E733ACB441680331B808636");
