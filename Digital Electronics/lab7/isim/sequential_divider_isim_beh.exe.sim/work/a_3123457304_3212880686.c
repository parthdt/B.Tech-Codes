/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/Study Material/lab7/sequential_divider.vhd";
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1547270861_1035706684(char *, char *, char *, char *, char *, char *);
int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);


static void work_a_3123457304_3212880686_p_0(char *t0)
{
    char t18[16];
    char t24[16];
    char t32[16];
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    int t9;
    int t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    char *t15;
    int t16;
    unsigned char t17;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t25;
    char *t26;
    int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    char *t33;
    char *t34;
    int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned char t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;

LAB0:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2152U);
    t4 = *((char **)t2);
    t2 = (t0 + 4144);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t4, 8U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 1832U);
    t4 = *((char **)t2);
    t21 = (15 - 7);
    t22 = (t21 * 1U);
    t23 = (0 + t22);
    t2 = (t4 + t23);
    t5 = (t0 + 4208);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    memcpy(t14, t2, 8U);
    xsi_driver_first_trans_fast_port(t5);
    t2 = (t0 + 3872);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(56, ng0);
    t4 = (t0 + 6420);
    *((int *)t4) = 0;
    t8 = (t0 + 6424);
    *((int *)t8) = 7;
    t9 = 0;
    t10 = 7;

LAB8:    if (t9 <= t10)
        goto LAB9;

LAB11:    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB9:    xsi_set_current_line(58, ng0);
    t11 = (t0 + 1992U);
    t12 = *((char **)t11);
    t11 = (t0 + 6308U);
    t13 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t12, t11);
    t14 = (t0 + 1832U);
    t15 = *((char **)t14);
    t14 = (t0 + 6292U);
    t16 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t15, t14);
    t17 = (t13 < t16);
    if (t17 != 0)
        goto LAB12;

LAB14:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2152U);
    t4 = *((char **)t2);
    t21 = (7 - 6);
    t22 = (t21 * 1U);
    t23 = (0 + t22);
    t2 = (t4 + t23);
    t5 = (t0 + 6429);
    t12 = ((IEEE_P_1242562249) + 3000);
    t14 = (t24 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 6;
    t15 = (t14 + 4U);
    *((int *)t15) = 0;
    t15 = (t14 + 8U);
    *((int *)t15) = -1;
    t13 = (0 - 6);
    t28 = (t13 * -1);
    t28 = (t28 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t28;
    t15 = (t32 + 0U);
    t19 = (t15 + 0U);
    *((int *)t19) = 0;
    t19 = (t15 + 4U);
    *((int *)t19) = 0;
    t19 = (t15 + 8U);
    *((int *)t19) = 1;
    t16 = (0 - 0);
    t28 = (t16 * 1);
    t28 = (t28 + 1);
    t19 = (t15 + 12U);
    *((unsigned int *)t19) = t28;
    t11 = xsi_base_array_concat(t11, t18, t12, (char)97, t2, t24, (char)97, t5, t32, (char)101);
    t28 = (7U + 1U);
    t1 = (8U != t28);
    if (t1 == 1)
        goto LAB19;

LAB20:    t19 = (t0 + 4016);
    t20 = (t19 + 56U);
    t25 = *((char **)t20);
    t26 = (t25 + 56U);
    t29 = *((char **)t26);
    memcpy(t29, t11, 8U);
    xsi_driver_first_trans_fast(t19);

LAB13:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 6430);
    t5 = (t0 + 1992U);
    t8 = *((char **)t5);
    t21 = (15 - 15);
    t22 = (t21 * 1U);
    t23 = (0 + t22);
    t5 = (t8 + t23);
    t12 = ((IEEE_P_1242562249) + 3000);
    t14 = (t24 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 0;
    t15 = (t14 + 4U);
    *((int *)t15) = 0;
    t15 = (t14 + 8U);
    *((int *)t15) = 1;
    t13 = (0 - 0);
    t28 = (t13 * 1);
    t28 = (t28 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t28;
    t15 = (t32 + 0U);
    t19 = (t15 + 0U);
    *((int *)t19) = 15;
    t19 = (t15 + 4U);
    *((int *)t19) = 1;
    t19 = (t15 + 8U);
    *((int *)t19) = -1;
    t16 = (1 - 15);
    t28 = (t16 * -1);
    t28 = (t28 + 1);
    t19 = (t15 + 12U);
    *((unsigned int *)t19) = t28;
    t11 = xsi_base_array_concat(t11, t18, t12, (char)97, t2, t24, (char)97, t5, t32, (char)101);
    t28 = (1U + 15U);
    t1 = (16U != t28);
    if (t1 == 1)
        goto LAB21;

LAB22:    t19 = (t0 + 4080);
    t20 = (t19 + 56U);
    t25 = *((char **)t20);
    t26 = (t25 + 56U);
    t29 = *((char **)t26);
    memcpy(t29, t11, 16U);
    xsi_driver_first_trans_fast(t19);

LAB10:    t2 = (t0 + 6420);
    t9 = *((int *)t2);
    t4 = (t0 + 6424);
    t10 = *((int *)t4);
    if (t9 == t10)
        goto LAB11;

LAB23:    t13 = (t9 + 1);
    t9 = t13;
    t5 = (t0 + 6420);
    *((int *)t5) = t9;
    goto LAB8;

LAB12:    xsi_set_current_line(59, ng0);
    t19 = (t0 + 1832U);
    t20 = *((char **)t19);
    t21 = (15 - 15);
    t22 = (t21 * 1U);
    t23 = (0 + t22);
    t19 = (t20 + t23);
    t25 = (t24 + 0U);
    t26 = (t25 + 0U);
    *((int *)t26) = 15;
    t26 = (t25 + 4U);
    *((int *)t26) = 0;
    t26 = (t25 + 8U);
    *((int *)t26) = -1;
    t27 = (0 - 15);
    t28 = (t27 * -1);
    t28 = (t28 + 1);
    t26 = (t25 + 12U);
    *((unsigned int *)t26) = t28;
    t26 = (t0 + 1992U);
    t29 = *((char **)t26);
    t28 = (15 - 15);
    t30 = (t28 * 1U);
    t31 = (0 + t30);
    t26 = (t29 + t31);
    t33 = (t32 + 0U);
    t34 = (t33 + 0U);
    *((int *)t34) = 15;
    t34 = (t33 + 4U);
    *((int *)t34) = 0;
    t34 = (t33 + 8U);
    *((int *)t34) = -1;
    t35 = (0 - 15);
    t36 = (t35 * -1);
    t36 = (t36 + 1);
    t34 = (t33 + 12U);
    *((unsigned int *)t34) = t36;
    t34 = ieee_p_1242562249_sub_1547270861_1035706684(IEEE_P_1242562249, t18, t19, t24, t26, t32);
    t37 = (t18 + 12U);
    t36 = *((unsigned int *)t37);
    t38 = (1U * t36);
    t39 = (16U != t38);
    if (t39 == 1)
        goto LAB15;

LAB16:    t40 = (t0 + 3952);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    memcpy(t44, t34, 16U);
    xsi_driver_first_trans_fast(t40);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 2152U);
    t4 = *((char **)t2);
    t21 = (7 - 6);
    t22 = (t21 * 1U);
    t23 = (0 + t22);
    t2 = (t4 + t23);
    t5 = (t0 + 6428);
    t12 = ((IEEE_P_1242562249) + 3000);
    t14 = (t24 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 6;
    t15 = (t14 + 4U);
    *((int *)t15) = 0;
    t15 = (t14 + 8U);
    *((int *)t15) = -1;
    t13 = (0 - 6);
    t28 = (t13 * -1);
    t28 = (t28 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t28;
    t15 = (t32 + 0U);
    t19 = (t15 + 0U);
    *((int *)t19) = 0;
    t19 = (t15 + 4U);
    *((int *)t19) = 0;
    t19 = (t15 + 8U);
    *((int *)t19) = 1;
    t16 = (0 - 0);
    t28 = (t16 * 1);
    t28 = (t28 + 1);
    t19 = (t15 + 12U);
    *((unsigned int *)t19) = t28;
    t11 = xsi_base_array_concat(t11, t18, t12, (char)97, t2, t24, (char)97, t5, t32, (char)101);
    t28 = (7U + 1U);
    t1 = (8U != t28);
    if (t1 == 1)
        goto LAB17;

LAB18:    t19 = (t0 + 4016);
    t20 = (t19 + 56U);
    t25 = *((char **)t20);
    t26 = (t25 + 56U);
    t29 = *((char **)t26);
    memcpy(t29, t11, 8U);
    xsi_driver_first_trans_fast(t19);
    goto LAB13;

LAB15:    xsi_size_not_matching(16U, t38, 0);
    goto LAB16;

LAB17:    xsi_size_not_matching(8U, t28, 0);
    goto LAB18;

LAB19:    xsi_size_not_matching(8U, t28, 0);
    goto LAB20;

LAB21:    xsi_size_not_matching(16U, t28, 0);
    goto LAB22;

}


extern void work_a_3123457304_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3123457304_3212880686_p_0};
	xsi_register_didat("work_a_3123457304_3212880686", "isim/sequential_divider_isim_beh.exe.sim/work/a_3123457304_3212880686.didat");
	xsi_register_executes(pe);
}
