/********************************** (C) COPYRIGHT *******************************
* File Name          : GUI_init.h 
* Author             : yvan
* Version            : V1.0.0
* Date               : 2026/06/10
* Description        : Reference files for all GUI functions called in this project
*******************************************************************************/

#ifndef __GUI_INIT_H__
#define __GUI_INIT_H__

#include <rtthread.h>

/* 导出邮箱给传感器线程使用 */
extern struct rt_mailbox gui_mb;

void GUI_INIT(void);

#endif /* __GUI_INIT_H__ */
