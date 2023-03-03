
/* Copyright (c) 2022-2023 Douglas H. Summerville (dsummer@binghamton.edu) 
 *
 * Created from scraped data which is Copyright (c) 2022 Raspberry Pi
 * (Trading) Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef M0PLUS_H
#define M0PLUS_H

#include <stdint.h>

#define ALL1 ((uint32_t)0xFFFFFFFF)

typedef struct{
		uint32_t RSVD0[14340];
		uint32_t syst_csr;
		uint32_t syst_rvr;
		uint32_t syst_cvr;
		uint32_t syst_calib;
		uint32_t RSVD1[56];
		uint32_t nvic_iser;
		uint32_t RSVD2[31];
		uint32_t nvic_icer;
		uint32_t RSVD3[31];
		uint32_t nvic_ispr;
		uint32_t RSVD4[31];
		uint32_t nvic_icpr;
		uint32_t RSVD5[95];
		uint32_t nvic_ipr0;
		uint32_t nvic_ipr1;
		uint32_t nvic_ipr2;
		uint32_t nvic_ipr3;
		uint32_t nvic_ipr4;
		uint32_t nvic_ipr5;
		uint32_t nvic_ipr6;
		uint32_t nvic_ipr7;
		uint32_t RSVD6[568];
		uint32_t cpuid;
		uint32_t icsr;
		uint32_t vtor;
		uint32_t aircr;
		uint32_t scr;
		uint32_t ccr;
		uint32_t RSVD7;
		uint32_t shpr2;
		uint32_t shpr3;
		uint32_t shcsr;
		uint32_t RSVD8[26];
		uint32_t mpu_type;
		uint32_t mpu_ctrl;
		uint32_t mpu_rnr;
		uint32_t mpu_rbar;
		uint32_t mpu_rasr;
} M0PLUS_REG_BLOCKS;

#define m0plus ((M0PLUS_REG_BLOCKS volatile *)0xe0000000)

/*SYST_CSR Register macros*/

#define M0PLUS_SYST_CSR_COUNTFLAG(v) (((v)&0x1)<<16)
#define M0PLUS_SYST_CSR_COUNTFLAG_MASK M0PLUS_SYST_CSR_COUNTFLAG(ALL1)
#define M0PLUS_SYST_CSR_CLKSOURCE(v) (((v)&0x1)<<2)
#define M0PLUS_SYST_CSR_CLKSOURCE_MASK M0PLUS_SYST_CSR_CLKSOURCE(ALL1)
#define M0PLUS_SYST_CSR_TICKINT(v) (((v)&0x1)<<1)
#define M0PLUS_SYST_CSR_TICKINT_MASK M0PLUS_SYST_CSR_TICKINT(ALL1)
#define M0PLUS_SYST_CSR_ENABLE(v) (((v)&0x1)<<0)
#define M0PLUS_SYST_CSR_ENABLE_MASK M0PLUS_SYST_CSR_ENABLE(ALL1)

/*SYST_RVR Register macros*/

#define M0PLUS_SYST_RVR_RELOAD(v) (((v)&0xffffff)<<0)
#define M0PLUS_SYST_RVR_RELOAD_MASK M0PLUS_SYST_RVR_RELOAD(ALL1)

/*SYST_CVR Register macros*/

#define M0PLUS_SYST_CVR_CURRENT(v) (((v)&0xffffff)<<0)
#define M0PLUS_SYST_CVR_CURRENT_MASK M0PLUS_SYST_CVR_CURRENT(ALL1)

/*SYST_CALIB Register macros*/

#define M0PLUS_SYST_CALIB_NOREF(v) (((v)&0x1)<<31)
#define M0PLUS_SYST_CALIB_NOREF_MASK M0PLUS_SYST_CALIB_NOREF(ALL1)
#define M0PLUS_SYST_CALIB_SKEW(v) (((v)&0x1)<<30)
#define M0PLUS_SYST_CALIB_SKEW_MASK M0PLUS_SYST_CALIB_SKEW(ALL1)
#define M0PLUS_SYST_CALIB_TENMS(v) (((v)&0xffffff)<<0)
#define M0PLUS_SYST_CALIB_TENMS_MASK M0PLUS_SYST_CALIB_TENMS(ALL1)

/*NVIC_ISER Register macros*/

#define M0PLUS_NVIC_ISER_SETENA(v) (((v)&0xffffffff)<<0)
#define M0PLUS_NVIC_ISER_SETENA_MASK M0PLUS_NVIC_ISER_SETENA(ALL1)

/*NVIC_ICER Register macros*/

#define M0PLUS_NVIC_ICER_CLRENA(v) (((v)&0xffffffff)<<0)
#define M0PLUS_NVIC_ICER_CLRENA_MASK M0PLUS_NVIC_ICER_CLRENA(ALL1)

/*NVIC_ISPR Register macros*/

#define M0PLUS_NVIC_ISPR_SETPEND(v) (((v)&0xffffffff)<<0)
#define M0PLUS_NVIC_ISPR_SETPEND_MASK M0PLUS_NVIC_ISPR_SETPEND(ALL1)

/*NVIC_ICPR Register macros*/

#define M0PLUS_NVIC_ICPR_CLRPEND(v) (((v)&0xffffffff)<<0)
#define M0PLUS_NVIC_ICPR_CLRPEND_MASK M0PLUS_NVIC_ICPR_CLRPEND(ALL1)

/*NVIC_IPR0 Register macros*/

#define M0PLUS_NVIC_IPR0_IP_3(v) (((v)&0x3)<<30)
#define M0PLUS_NVIC_IPR0_IP_3_MASK M0PLUS_NVIC_IPR0_IP_3(ALL1)
#define M0PLUS_NVIC_IPR0_IP_2(v) (((v)&0x3)<<22)
#define M0PLUS_NVIC_IPR0_IP_2_MASK M0PLUS_NVIC_IPR0_IP_2(ALL1)
#define M0PLUS_NVIC_IPR0_IP_1(v) (((v)&0x3)<<14)
#define M0PLUS_NVIC_IPR0_IP_1_MASK M0PLUS_NVIC_IPR0_IP_1(ALL1)
#define M0PLUS_NVIC_IPR0_IP_0(v) (((v)&0x3)<<6)
#define M0PLUS_NVIC_IPR0_IP_0_MASK M0PLUS_NVIC_IPR0_IP_0(ALL1)

/*NVIC_IPR1 Register macros*/

#define M0PLUS_NVIC_IPR1_IP_7(v) (((v)&0x3)<<30)
#define M0PLUS_NVIC_IPR1_IP_7_MASK M0PLUS_NVIC_IPR1_IP_7(ALL1)
#define M0PLUS_NVIC_IPR1_IP_6(v) (((v)&0x3)<<22)
#define M0PLUS_NVIC_IPR1_IP_6_MASK M0PLUS_NVIC_IPR1_IP_6(ALL1)
#define M0PLUS_NVIC_IPR1_IP_5(v) (((v)&0x3)<<14)
#define M0PLUS_NVIC_IPR1_IP_5_MASK M0PLUS_NVIC_IPR1_IP_5(ALL1)
#define M0PLUS_NVIC_IPR1_IP_4(v) (((v)&0x3)<<6)
#define M0PLUS_NVIC_IPR1_IP_4_MASK M0PLUS_NVIC_IPR1_IP_4(ALL1)

/*NVIC_IPR2 Register macros*/

#define M0PLUS_NVIC_IPR2_IP_11(v) (((v)&0x3)<<30)
#define M0PLUS_NVIC_IPR2_IP_11_MASK M0PLUS_NVIC_IPR2_IP_11(ALL1)
#define M0PLUS_NVIC_IPR2_IP_10(v) (((v)&0x3)<<22)
#define M0PLUS_NVIC_IPR2_IP_10_MASK M0PLUS_NVIC_IPR2_IP_10(ALL1)
#define M0PLUS_NVIC_IPR2_IP_9(v) (((v)&0x3)<<14)
#define M0PLUS_NVIC_IPR2_IP_9_MASK M0PLUS_NVIC_IPR2_IP_9(ALL1)
#define M0PLUS_NVIC_IPR2_IP_8(v) (((v)&0x3)<<6)
#define M0PLUS_NVIC_IPR2_IP_8_MASK M0PLUS_NVIC_IPR2_IP_8(ALL1)

/*NVIC_IPR3 Register macros*/

#define M0PLUS_NVIC_IPR3_IP_15(v) (((v)&0x3)<<30)
#define M0PLUS_NVIC_IPR3_IP_15_MASK M0PLUS_NVIC_IPR3_IP_15(ALL1)
#define M0PLUS_NVIC_IPR3_IP_14(v) (((v)&0x3)<<22)
#define M0PLUS_NVIC_IPR3_IP_14_MASK M0PLUS_NVIC_IPR3_IP_14(ALL1)
#define M0PLUS_NVIC_IPR3_IP_13(v) (((v)&0x3)<<14)
#define M0PLUS_NVIC_IPR3_IP_13_MASK M0PLUS_NVIC_IPR3_IP_13(ALL1)
#define M0PLUS_NVIC_IPR3_IP_12(v) (((v)&0x3)<<6)
#define M0PLUS_NVIC_IPR3_IP_12_MASK M0PLUS_NVIC_IPR3_IP_12(ALL1)

/*NVIC_IPR4 Register macros*/

#define M0PLUS_NVIC_IPR4_IP_19(v) (((v)&0x3)<<30)
#define M0PLUS_NVIC_IPR4_IP_19_MASK M0PLUS_NVIC_IPR4_IP_19(ALL1)
#define M0PLUS_NVIC_IPR4_IP_18(v) (((v)&0x3)<<22)
#define M0PLUS_NVIC_IPR4_IP_18_MASK M0PLUS_NVIC_IPR4_IP_18(ALL1)
#define M0PLUS_NVIC_IPR4_IP_17(v) (((v)&0x3)<<14)
#define M0PLUS_NVIC_IPR4_IP_17_MASK M0PLUS_NVIC_IPR4_IP_17(ALL1)
#define M0PLUS_NVIC_IPR4_IP_16(v) (((v)&0x3)<<6)
#define M0PLUS_NVIC_IPR4_IP_16_MASK M0PLUS_NVIC_IPR4_IP_16(ALL1)

/*NVIC_IPR5 Register macros*/

#define M0PLUS_NVIC_IPR5_IP_23(v) (((v)&0x3)<<30)
#define M0PLUS_NVIC_IPR5_IP_23_MASK M0PLUS_NVIC_IPR5_IP_23(ALL1)
#define M0PLUS_NVIC_IPR5_IP_22(v) (((v)&0x3)<<22)
#define M0PLUS_NVIC_IPR5_IP_22_MASK M0PLUS_NVIC_IPR5_IP_22(ALL1)
#define M0PLUS_NVIC_IPR5_IP_21(v) (((v)&0x3)<<14)
#define M0PLUS_NVIC_IPR5_IP_21_MASK M0PLUS_NVIC_IPR5_IP_21(ALL1)
#define M0PLUS_NVIC_IPR5_IP_20(v) (((v)&0x3)<<6)
#define M0PLUS_NVIC_IPR5_IP_20_MASK M0PLUS_NVIC_IPR5_IP_20(ALL1)

/*NVIC_IPR6 Register macros*/

#define M0PLUS_NVIC_IPR6_IP_27(v) (((v)&0x3)<<30)
#define M0PLUS_NVIC_IPR6_IP_27_MASK M0PLUS_NVIC_IPR6_IP_27(ALL1)
#define M0PLUS_NVIC_IPR6_IP_26(v) (((v)&0x3)<<22)
#define M0PLUS_NVIC_IPR6_IP_26_MASK M0PLUS_NVIC_IPR6_IP_26(ALL1)
#define M0PLUS_NVIC_IPR6_IP_25(v) (((v)&0x3)<<14)
#define M0PLUS_NVIC_IPR6_IP_25_MASK M0PLUS_NVIC_IPR6_IP_25(ALL1)
#define M0PLUS_NVIC_IPR6_IP_24(v) (((v)&0x3)<<6)
#define M0PLUS_NVIC_IPR6_IP_24_MASK M0PLUS_NVIC_IPR6_IP_24(ALL1)

/*NVIC_IPR7 Register macros*/

#define M0PLUS_NVIC_IPR7_IP_31(v) (((v)&0x3)<<30)
#define M0PLUS_NVIC_IPR7_IP_31_MASK M0PLUS_NVIC_IPR7_IP_31(ALL1)
#define M0PLUS_NVIC_IPR7_IP_30(v) (((v)&0x3)<<22)
#define M0PLUS_NVIC_IPR7_IP_30_MASK M0PLUS_NVIC_IPR7_IP_30(ALL1)
#define M0PLUS_NVIC_IPR7_IP_29(v) (((v)&0x3)<<14)
#define M0PLUS_NVIC_IPR7_IP_29_MASK M0PLUS_NVIC_IPR7_IP_29(ALL1)
#define M0PLUS_NVIC_IPR7_IP_28(v) (((v)&0x3)<<6)
#define M0PLUS_NVIC_IPR7_IP_28_MASK M0PLUS_NVIC_IPR7_IP_28(ALL1)

/*CPUID Register macros*/

#define M0PLUS_CPUID_IMPLEMENTER(v) (((v)&0xff)<<24)
#define M0PLUS_CPUID_IMPLEMENTER_MASK M0PLUS_CPUID_IMPLEMENTER(ALL1)
#define M0PLUS_CPUID_VARIANT(v) (((v)&0xf)<<20)
#define M0PLUS_CPUID_VARIANT_MASK M0PLUS_CPUID_VARIANT(ALL1)
#define M0PLUS_CPUID_ARCHITECTURE(v) (((v)&0xf)<<16)
#define M0PLUS_CPUID_ARCHITECTURE_MASK M0PLUS_CPUID_ARCHITECTURE(ALL1)
#define M0PLUS_CPUID_PARTNO(v) (((v)&0xfff)<<4)
#define M0PLUS_CPUID_PARTNO_MASK M0PLUS_CPUID_PARTNO(ALL1)
#define M0PLUS_CPUID_REVISION(v) (((v)&0xf)<<0)
#define M0PLUS_CPUID_REVISION_MASK M0PLUS_CPUID_REVISION(ALL1)

/*ICSR Register macros*/

#define M0PLUS_ICSR_NMIPENDSET(v) (((v)&0x1)<<31)
#define M0PLUS_ICSR_NMIPENDSET_MASK M0PLUS_ICSR_NMIPENDSET(ALL1)
#define M0PLUS_ICSR_PENDSVSET(v) (((v)&0x1)<<28)
#define M0PLUS_ICSR_PENDSVSET_MASK M0PLUS_ICSR_PENDSVSET(ALL1)
#define M0PLUS_ICSR_PENDSVCLR(v) (((v)&0x1)<<27)
#define M0PLUS_ICSR_PENDSVCLR_MASK M0PLUS_ICSR_PENDSVCLR(ALL1)
#define M0PLUS_ICSR_PENDSTSET(v) (((v)&0x1)<<26)
#define M0PLUS_ICSR_PENDSTSET_MASK M0PLUS_ICSR_PENDSTSET(ALL1)
#define M0PLUS_ICSR_PENDSTCLR(v) (((v)&0x1)<<25)
#define M0PLUS_ICSR_PENDSTCLR_MASK M0PLUS_ICSR_PENDSTCLR(ALL1)
#define M0PLUS_ICSR_ISRPREEMPT(v) (((v)&0x1)<<23)
#define M0PLUS_ICSR_ISRPREEMPT_MASK M0PLUS_ICSR_ISRPREEMPT(ALL1)
#define M0PLUS_ICSR_ISRPENDING(v) (((v)&0x1)<<22)
#define M0PLUS_ICSR_ISRPENDING_MASK M0PLUS_ICSR_ISRPENDING(ALL1)
#define M0PLUS_ICSR_VECTPENDING(v) (((v)&0x1ff)<<12)
#define M0PLUS_ICSR_VECTPENDING_MASK M0PLUS_ICSR_VECTPENDING(ALL1)
#define M0PLUS_ICSR_VECTACTIVE(v) (((v)&0x1ff)<<0)
#define M0PLUS_ICSR_VECTACTIVE_MASK M0PLUS_ICSR_VECTACTIVE(ALL1)

/*VTOR Register macros*/

#define M0PLUS_VTOR_TBLOFF(v) (((v)&0xffffff)<<8)
#define M0PLUS_VTOR_TBLOFF_MASK M0PLUS_VTOR_TBLOFF(ALL1)

/*AIRCR Register macros*/

#define M0PLUS_AIRCR_VECTKEY(v) (((v)&0xffff)<<16)
#define M0PLUS_AIRCR_VECTKEY_MASK M0PLUS_AIRCR_VECTKEY(ALL1)
#define M0PLUS_AIRCR_ENDIANESS(v) (((v)&0x1)<<15)
#define M0PLUS_AIRCR_ENDIANESS_MASK M0PLUS_AIRCR_ENDIANESS(ALL1)
#define M0PLUS_AIRCR_SYSRESETREQ(v) (((v)&0x1)<<2)
#define M0PLUS_AIRCR_SYSRESETREQ_MASK M0PLUS_AIRCR_SYSRESETREQ(ALL1)
#define M0PLUS_AIRCR_VECTCLRACTIVE(v) (((v)&0x1)<<1)
#define M0PLUS_AIRCR_VECTCLRACTIVE_MASK M0PLUS_AIRCR_VECTCLRACTIVE(ALL1)

/*SCR Register macros*/

#define M0PLUS_SCR_SEVONPEND(v) (((v)&0x1)<<4)
#define M0PLUS_SCR_SEVONPEND_MASK M0PLUS_SCR_SEVONPEND(ALL1)
#define M0PLUS_SCR_SLEEPDEEP(v) (((v)&0x1)<<2)
#define M0PLUS_SCR_SLEEPDEEP_MASK M0PLUS_SCR_SLEEPDEEP(ALL1)
#define M0PLUS_SCR_SLEEPONEXIT(v) (((v)&0x1)<<1)
#define M0PLUS_SCR_SLEEPONEXIT_MASK M0PLUS_SCR_SLEEPONEXIT(ALL1)

/*CCR Register macros*/

#define M0PLUS_CCR_STKALIGN(v) (((v)&0x1)<<9)
#define M0PLUS_CCR_STKALIGN_MASK M0PLUS_CCR_STKALIGN(ALL1)
#define M0PLUS_CCR_UNALIGN_TRP(v) (((v)&0x1)<<3)
#define M0PLUS_CCR_UNALIGN_TRP_MASK M0PLUS_CCR_UNALIGN_TRP(ALL1)

/*SHPR2 Register macros*/

#define M0PLUS_SHPR2_PRI_11(v) (((v)&0x3)<<30)
#define M0PLUS_SHPR2_PRI_11_MASK M0PLUS_SHPR2_PRI_11(ALL1)

/*SHPR3 Register macros*/

#define M0PLUS_SHPR3_PRI_15(v) (((v)&0x3)<<30)
#define M0PLUS_SHPR3_PRI_15_MASK M0PLUS_SHPR3_PRI_15(ALL1)
#define M0PLUS_SHPR3_PRI_14(v) (((v)&0x3)<<22)
#define M0PLUS_SHPR3_PRI_14_MASK M0PLUS_SHPR3_PRI_14(ALL1)

/*SHCSR Register macros*/

#define M0PLUS_SHCSR_SVCALLPENDED(v) (((v)&0x1)<<15)
#define M0PLUS_SHCSR_SVCALLPENDED_MASK M0PLUS_SHCSR_SVCALLPENDED(ALL1)

/*MPU_TYPE Register macros*/

#define M0PLUS_MPU_TYPE_IREGION(v) (((v)&0xff)<<16)
#define M0PLUS_MPU_TYPE_IREGION_MASK M0PLUS_MPU_TYPE_IREGION(ALL1)
#define M0PLUS_MPU_TYPE_DREGION(v) (((v)&0xff)<<8)
#define M0PLUS_MPU_TYPE_DREGION_MASK M0PLUS_MPU_TYPE_DREGION(ALL1)
#define M0PLUS_MPU_TYPE_SEPARATE(v) (((v)&0x1)<<0)
#define M0PLUS_MPU_TYPE_SEPARATE_MASK M0PLUS_MPU_TYPE_SEPARATE(ALL1)

/*MPU_CTRL Register macros*/

#define M0PLUS_MPU_CTRL_PRIVDEFENA(v) (((v)&0x1)<<2)
#define M0PLUS_MPU_CTRL_PRIVDEFENA_MASK M0PLUS_MPU_CTRL_PRIVDEFENA(ALL1)
#define M0PLUS_MPU_CTRL_HFNMIENA(v) (((v)&0x1)<<1)
#define M0PLUS_MPU_CTRL_HFNMIENA_MASK M0PLUS_MPU_CTRL_HFNMIENA(ALL1)
#define M0PLUS_MPU_CTRL_ENABLE(v) (((v)&0x1)<<0)
#define M0PLUS_MPU_CTRL_ENABLE_MASK M0PLUS_MPU_CTRL_ENABLE(ALL1)

/*MPU_RNR Register macros*/

#define M0PLUS_MPU_RNR_REGION(v) (((v)&0xf)<<0)
#define M0PLUS_MPU_RNR_REGION_MASK M0PLUS_MPU_RNR_REGION(ALL1)

/*MPU_RBAR Register macros*/

#define M0PLUS_MPU_RBAR_ADDR(v) (((v)&0xffffff)<<8)
#define M0PLUS_MPU_RBAR_ADDR_MASK M0PLUS_MPU_RBAR_ADDR(ALL1)
#define M0PLUS_MPU_RBAR_VALID(v) (((v)&0x1)<<4)
#define M0PLUS_MPU_RBAR_VALID_MASK M0PLUS_MPU_RBAR_VALID(ALL1)
#define M0PLUS_MPU_RBAR_REGION(v) (((v)&0xf)<<0)
#define M0PLUS_MPU_RBAR_REGION_MASK M0PLUS_MPU_RBAR_REGION(ALL1)

/*MPU_RASR Register macros*/

#define M0PLUS_MPU_RASR_ATTRS(v) (((v)&0xffff)<<16)
#define M0PLUS_MPU_RASR_ATTRS_MASK M0PLUS_MPU_RASR_ATTRS(ALL1)
#define M0PLUS_MPU_RASR_SRD(v) (((v)&0xff)<<8)
#define M0PLUS_MPU_RASR_SRD_MASK M0PLUS_MPU_RASR_SRD(ALL1)
#define M0PLUS_MPU_RASR_SIZE(v) (((v)&0x1f)<<1)
#define M0PLUS_MPU_RASR_SIZE_MASK M0PLUS_MPU_RASR_SIZE(ALL1)
#define M0PLUS_MPU_RASR_ENABLE(v) (((v)&0x1)<<0)
#define M0PLUS_MPU_RASR_ENABLE_MASK M0PLUS_MPU_RASR_ENABLE(ALL1)

#endif