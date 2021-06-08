#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/version.h>

#define LKM_INFO "MY_LKM"
#define LKM_VERSION "0.1"

MODULE_AUTHOR("yzhu");
MODULE_DESCRIPTION("simple lkm test.");
MODULE_LICENSE("GPL");


static int simple_test_init(void)
{

#ifdef RHEL_MAJOR // rhel/centos
	printk("%s %s. RHEL:%d.%d\n", LKM_INFO, __func__, RHEL_MAJOR, RHEL_MINOR);
#endif

	printk("%s %s. load success!\n", LKM_INFO, __func__);

	return 0;
}

static void simple_test_cleanup(void)
{
	printk("%s %s. unload fin. bye!\n", LKM_INFO, __func__);
}

module_init(simple_test_init);
module_exit(simple_test_cleanup);
