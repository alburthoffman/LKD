obj-m += usb_kb_module.o

ifdef KERNEL_DIR
	KDIR=$(KERNEL_DIR)
else
	KDIR=/lib/modules/$(shell uname -r)/build
endif

all:
	make -C ${KDIR} M=$(PWD) modules

clean:
	make -C ${KDIR} M=$(PWD) clean

