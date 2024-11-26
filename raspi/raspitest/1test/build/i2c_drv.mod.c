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
	{ 0x122c3a7e, "_printk" },
	{ 0xfe266025, "i2c_register_driver" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x3fa498ad, "class_create" },
	{ 0xfbe72bcf, "device_create" },
	{ 0xe78e8907, "cdev_init" },
	{ 0x39f012c6, "cdev_add" },
	{ 0xb02e77f7, "i2c_del_driver" },
	{ 0xb86bb5ac, "device_destroy" },
	{ 0xa4e5832c, "class_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x6dfbc1bf, "proc_remove" },
	{ 0xcc2dfa4f, "device_property_present" },
	{ 0xf4576471, "device_property_read_u32_array" },
	{ 0xd77a80e5, "proc_mkdir" },
	{ 0xa6875084, "proc_create" },
	{ 0xa4afd25e, "cdev_del" },
	{ 0xdcb764ad, "memset" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0x86c9432a, "i2c_transfer_buffer_flags" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x6cbbfc54, "__arch_copy_to_user" },
	{ 0x67a35d9, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:i2c_dev");
MODULE_ALIAS("of:N*T*Ctd3_i2c");
MODULE_ALIAS("of:N*T*Ctd3_i2cC*");

MODULE_INFO(srcversion, "AE838532A5457AE714B8229");