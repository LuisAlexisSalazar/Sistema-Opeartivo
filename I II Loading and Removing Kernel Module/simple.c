/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */


#include <linux/gcd.h>
#include <linux/hash.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
       printk(KERN_INFO "Golden Ratio si:%lu\n",GOLDEN_RATIO_PRIME);
 	printk(KERN_INFO "Los HZ:%d\n",HZ);
	printk(KERN_INFO "Los jiffies :%lu\n",jiffies);
      return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
	unsigned long a = gcd(3300,24);
	printk(KERN_INFO "Máximo Común Divisor de 3300 y 24 es:%lu\n",a);
	printk(KERN_INFO "Los jiffies :%lu\n",jiffies);

}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

