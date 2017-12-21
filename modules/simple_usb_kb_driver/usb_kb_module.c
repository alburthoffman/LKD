/*
 * usb_kb_module.c - the simplest usb keyboard module
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

MODULE_AUTHOR("alburthoffman");
MODULE_DESCRIPTION("simple usb keyboard module\n");
MODULE_LICENSE("GPL");

static struct usb_device_id usb_kb_id_table[] = {
	{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
	USB_INTERFACE_SUBCLASS_BOOT,
	USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{}
};

MODULE_DEVICE_TABLE(usb, usb_kb_id_table);

static int usb_kb_probe(struct usb_interface *interface,
	const struct usb_device_id *id)
{
	pr_debug("USB Keyboard probe\n");
	return 0;
}

static void usb_kb_disconnect(struct usb_interface *interface)
{
	pr_debug("USB Keyboard disconnect\n");
}

static struct usb_driver usb_kb_driver = {
	/*.owner = THIS_MODULE,*/
	.name = "usb_kb_driver",
	.probe = usb_kb_probe,
	.disconnect = usb_kb_disconnect,
	.id_table = usb_kb_id_table
};

int init_module(void)
{
	int retval = 0;

	pr_debug("init usb keyboard module\n");

	retval = usb_register(&usb_kb_driver);
	if (retval)
		pr_debug("usb_register fails.\n");

	return 0;
}

void cleanup_module(void)
{
	usb_deregister(&usb_kb_driver);
	pr_debug("cleanup usb keyboard module\n");
}
