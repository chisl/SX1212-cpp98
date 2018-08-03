/*
 * name:        SX1212
 * description: Ultra-Low Power Integrated 300-510MHz Transceiver
 * manuf:       Semtech
 * version:     Version 0.1
 * url:         https://www.semtech.com/uploads/documents/sx1272.pdf
 * date:        2018-07-31
 * author       https://chisl.io/
 * file:        SX1212.hpp
 * types:       RF
 */
/*                                                                                                       *
 *                                   THIS FILE IS AUTOMATICALLY CREATED                                  *
 *                                    D O     N O T     M O D I F Y  !                                   *
 *                                                                                                       */
#include <cinttypes>
/* Derive from class SX1212_Base and implement the read and write functions! */
/* SX1212: Ultra-Low Power Integrated 300-510MHz Transceiver */
class SX1212_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	virtual uint32_t read32(uint16_t address, uint16_t n=32) = 0;  // 32 bit read
	virtual void write(uint16_t address, uint32_t value, uint16_t n=32) = 0;  // 32 bit write
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG MCParam_1                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	/* REG MCParam_1:
	 */
	struct MCParam_1
	{
		static const uint16_t __address = 0;
		/* Bits Chip_mode: */
		/* Transceiver mode:  */
		struct Chip_mode
		{
			/* MODE rw */
			static const uint8_t dflt = 0b001; // 3'b1
			static const uint8_t mask = 0b11100000; // [5,6,7]
			static const uint8_t SLEEP = 0b00; // sleep mode
			static const uint8_t STBY = 0b01; // stand-by mode(d)
			static const uint8_t FS = 0b10; // frequency synthesizer mode
			static const uint8_t RX = 0b11; // receive mode
			static const uint8_t TX = 0b100; // transmit mode
		};
		/* Bits Freq_band: */
		/*
		 * 3.2.5.1. Frequency band.
		 * To guarantee the optimum operation of the VCO over the SX1212’s frequency and
		 * temperature ranges, the following settings should be programmed
		 */
		struct Freq_band
		{
			/* MODE rw */
			static const uint8_t dflt = 0b100; // 3'b100
			static const uint8_t mask = 0b00011100; // [2,3,4]
			static const uint8_t FREQ_300_330 = 0b00; // 300-330 MHz
			static const uint8_t FREQ_320_350 = 0b01; // 320-350 MHz
			static const uint8_t FREQ_350_390 = 0b10; // 350-390 MHz
			static const uint8_t FREQ_390_430 = 0b11; // 390-430 MHz
			static const uint8_t FREQ_430_470 = 0b100; // 430-470 MHz (d)
			static const uint8_t FREQ_470_510 = 0b101; // 470-510 MHz
		};
		/* Bits Subbband: */
		/* Frequency Sub-band:  */
		struct Subbband
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t SUB_BAND_1ST = 0b00; // 1st quarter of the selected band (d)
			static const uint8_t SUB_BAND_2ND = 0b01; // 2nd quarter of the selected band
			static const uint8_t SUB_BAND_3RD = 0b10; // 3rd quarter of the selected band
			static const uint8_t SUB_BAND_4TH = 0b11; // 4th quarter of the selected band
		};
	};
	/* Set register MCParam_1 */
	void setMCParam_1(uint8_t value)
	{
		write(MCParam_1::__address, value, 8);
	}
	/* Get register MCParam_1 */
	uint8_t getMCParam_1()
	{
		return read8(MCParam_1::__address, 8);
	}
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG MCParam_2                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	/* REG MCParam_2:
	 */
	struct MCParam_2
	{
		static const uint16_t __address = 1;
		/* Bits Data_mode: */
		/* Data operation mode:  */
		struct Data_mode
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
			static const uint8_t CONT = 0b00; // continuous mode (d)
			static const uint8_t BUFFERED = 0b01; // buffered mode
			static const uint8_t PACKET = 0b10; // packet handling mode (2'b1x)
		};
		/* Bits FSK_OOK_ctrl: */
		/* RxTx modulation scheme:  */
		struct FSK_OOK_ctrl
		{
			/* MODE rw */
			static const uint8_t dflt = 0b10; // 2'b10
			static const uint8_t mask = 0b00110000; // [4,5]
			static const uint8_t RESET = 0b00; // Reset
			static const uint8_t OOK = 0b01; // OOK
			static const uint8_t FSK = 0b10; // FSK (d)
			static const uint8_t DIRECT = 0b11; // Direct mode of transmitter (internal). Reserved (external)
		};
		/* Bits OOK_thresh_type: */
		/* OOK  demodulator threshold type:  */
		struct OOK_thresh_type
		{
			/* MODE rw */
			static const uint8_t dflt = 0b01; // 2'b1
			static const uint8_t mask = 0b00001100; // [2,3]
			static const uint8_t FIXED_THRESH = 0b00; // fixed threshold mode
			static const uint8_t PEAK = 0b01; // peak mode (d)
			static const uint8_t AVERAGE = 0b10; // average mode
			static const uint8_t reserved_0 = 0b11; // 
		};
		/* Bits IF_gain: */
		/* 3.4.2. Gain on the IF chain:  */
		struct IF_gain
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t GAIN_MAX = 0b00; // maximal gain (0dB) (d)
			static const uint8_t GAIN_MINUS_4_5 = 0b01; // -4.5 dB
			static const uint8_t GAIN_MINUS_9 = 0b10; // -9dB
			static const uint8_t GAIN_MINUS_13_5 = 0b11; // -13.5 dB §
		};
	};
	/* Set register MCParam_2 */
	void setMCParam_2(uint8_t value)
	{
		write(MCParam_2::__address, value, 8);
	}
	/* Get register MCParam_2 */
	uint8_t getMCParam_2()
	{
		return read8(MCParam_2::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                       REG MCParam_freq_dev                                        *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_freq_dev:
	 */
	struct MCParam_freq_dev
	{
		static const uint16_t __address = 2;
		/* Bits Freq_dev: */
		/*
		 * 3.3.4-5: Single side frequency deviation in FSK Transmit mode:
		 * Fdev = f_XTAL / (32 (D+1))          , 0 ≤ D ≤ 255, where D is the value in the register.
		 * (d): D = “00000011" => Fdev = 100 kHz
		 */
		struct Freq_dev
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000011; // 8'b11
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register MCParam_freq_dev */
	void setMCParam_freq_dev(uint8_t value)
	{
		write(MCParam_freq_dev::__address, value, 8);
	}
	/* Get register MCParam_freq_dev */
	uint8_t getMCParam_freq_dev()
	{
		return read8(MCParam_freq_dev::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG MCParam_BR_C                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_BR_C:
	 */
	struct MCParam_BR_C
	{
		static const uint16_t __address = 3;
		/* Bits BR_C: */
		/*
		 * C coefficient of the bit rate
		 * Bit Rate = f_XTAL / ( 2 ⋅ (C + 1).(D + 1) )  , 0 ≤ C ≤ 255, where C is the value in the register.
		 * (d): C =  “0000111"  => Bit Rate = 25 kb/s NRZ
		 */
		struct BR_C
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000111; // 8'b111
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register MCParam_BR_C */
	void setMCParam_BR_C(uint8_t value)
	{
		write(MCParam_BR_C::__address, value, 8);
	}
	/* Get register MCParam_BR_C */
	uint8_t getMCParam_BR_C()
	{
		return read8(MCParam_BR_C::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG MCParam_BR_D                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_BR_D:
	 */
	struct MCParam_BR_D
	{
		static const uint16_t __address = 4;
		/* Bits BR_D: */
		/*
		 * D coefficient of the bit rate
		 * Bit Rate =f_XTAL / ( 2 ⋅ (C + 1).(D + 1) ) , 15 ≤ D ≤ 255, where D is the value in the register.
		 * (d): D =  “0001111"  => Bit Rate = 25 kb/s NRZ
		 */
		struct BR_D
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000111; // 8'b111
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register MCParam_BR_D */
	void setMCParam_BR_D(uint8_t value)
	{
		write(MCParam_BR_D::__address, value, 8);
	}
	/* Get register MCParam_BR_D */
	uint8_t getMCParam_BR_D()
	{
		return read8(MCParam_BR_D::__address, 8);
	}
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG MCParam_6                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	/* REG MCParam_6:
	 */
	struct MCParam_6
	{
		static const uint16_t __address = 5;
		/* Bits PA_ramp: */
		/*
		 * 3.3.7.1. Ramp control of the rise and fall times of the Tx PA regulator output voltage in
		 * OOK mode:
		 */
		struct PA_ramp
		{
			/* MODE rw */
			static const uint8_t dflt = 0b11; // 2'b11
			static const uint8_t mask = 0b11000000; // [6,7]
			static const uint8_t RAMP_3us = 0b00; // 3us
			static const uint8_t RAMP_8_5us = 0b01; // 8.5 us
			static const uint8_t RAMP_15us = 0b10; // 15 us
			static const uint8_t RAMP_23s = 0b11; // 23 us (d)
		};
		/* Bits Low_power_rx: */
		/*
		 * Enables the low power mode of the receiver by reducing the bias current
		 * of the LNA.
		 */
		struct Low_power_rx
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t DISABLED = 0b0; // Low power mode disabled (d)
			static const uint8_t ENABLED = 0b1; // Low power mode enabled
		};
		/* Bits Trim_band: */
		/* VCO trimming: (d) 11  */
		struct Trim_band
		{
			/* MODE rw */
			static const uint8_t dflt = 0b11; // 2'b11
			static const uint8_t mask = 0b00000110; // [1,2]
		};
		/* Bits RF_frequency: */
		/*
		 * Selection between the two RF frequencies defined by the
		 * SynthRi, SynthPi, and SynthSi registers:
		 */
		struct RF_frequency
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t FREQ1 = 0b0; // frequency 1 for R1,P1,S1 (d)
			static const uint8_t FREQ2 = 0b1; // -> frequency 2 for R2,P2,S2 §
		};
	};
	/* Set register MCParam_6 */
	void setMCParam_6(uint8_t value)
	{
		write(MCParam_6::__address, value, 8);
	}
	/* Get register MCParam_6 */
	uint8_t getMCParam_6()
	{
		return read8(MCParam_6::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG MCParam_R1                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_R1:
	 */
	struct MCParam_R1
	{
		static const uint16_t __address = 6;
		/* Bits R1: */
		/*
		 * 3.2.8. R counter, active when RPS_select="0"
		 * (d):6Bh; default values of R1, P1, S1 generate 434.0 MHz in FSK mode
		 */
		struct R1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b01101011; // 8'h6b
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register MCParam_R1 */
	void setMCParam_R1(uint8_t value)
	{
		write(MCParam_R1::__address, value, 8);
	}
	/* Get register MCParam_R1 */
	uint8_t getMCParam_R1()
	{
		return read8(MCParam_R1::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG MCParam_P1                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_P1:
	 */
	struct MCParam_P1
	{
		static const uint16_t __address = 7;
		/* Bits P1: */
		/*
		 * 3.2.8. P counter, active when RPS_select="0"
		 * (d): 2Ah; default values of R1, P1, S1 generate 434.0 MHz in FSK mode
		 */
		struct P1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00101010; // 8'h2a
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register MCParam_P1 */
	void setMCParam_P1(uint8_t value)
	{
		write(MCParam_P1::__address, value, 8);
	}
	/* Get register MCParam_P1 */
	uint8_t getMCParam_P1()
	{
		return read8(MCParam_P1::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG MCParam_S1                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_S1:
	 */
	struct MCParam_S1
	{
		static const uint16_t __address = 8;
		/* Bits S1: */
		/*
		 * 3.2.8. S counter, active when RPS_select="0"
		 * (d): 1Eh; default values of R1, P1, S1 generate 434.0 MHz in FSK mode
		 */
		struct S1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00011110; // 8'h1e
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register MCParam_S1 */
	void setMCParam_S1(uint8_t value)
	{
		write(MCParam_S1::__address, value, 8);
	}
	/* Get register MCParam_S1 */
	uint8_t getMCParam_S1()
	{
		return read8(MCParam_S1::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG MCParam_R2                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_R2:
	 */
	struct MCParam_R2
	{
		static const uint16_t __address = 9;
		/* Bits R2: */
		/*
		 * 3.2.8. R counter, active when RPS_select="1"
		 * (d): 77h; default values of R2, P2, S2 generate 435.0 MHz in FSK mode
		 */
		struct R2
		{
			/* MODE rw */
			static const uint8_t dflt = 0b01110111; // 8'h77
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register MCParam_R2 */
	void setMCParam_R2(uint8_t value)
	{
		write(MCParam_R2::__address, value, 8);
	}
	/* Get register MCParam_R2 */
	uint8_t getMCParam_R2()
	{
		return read8(MCParam_R2::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG MCParam_P2                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_P2:
	 */
	struct MCParam_P2
	{
		static const uint16_t __address = 10;
		/* Bits P2: */
		/*
		 * 3.2.8. P counter, active when RPS_select="1"
		 * (d): 2Fh; default values of R2, P2, S2 generate 435.0 MHz in FSK mode
		 */
		struct P2
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00101111; // 8'h2f
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register MCParam_P2 */
	void setMCParam_P2(uint8_t value)
	{
		write(MCParam_P2::__address, value, 8);
	}
	/* Get register MCParam_P2 */
	uint8_t getMCParam_P2()
	{
		return read8(MCParam_P2::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG MCParam_S2                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_S2:
	 */
	struct MCParam_S2
	{
		static const uint16_t __address = 11;
		/* Bits S2: */
		/*
		 * 3.2.8. S counter, active when RPS_select="1"
		 * (d): 19h; default values of R2, P2, S2 generate 435.0 MHz in FSK mode
		 */
		struct S2
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00011001; // 8'h19
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register MCParam_S2 */
	void setMCParam_S2(uint8_t value)
	{
		write(MCParam_S2::__address, value, 8);
	}
	/* Get register MCParam_S2 */
	uint8_t getMCParam_S2()
	{
		return read8(MCParam_S2::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                       REG MCParam_reserved                                        *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG MCParam_reserved:
	 */
	struct MCParam_reserved
	{
		static const uint16_t __address = 12;
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00000111; // [0,1,2]
		};
	};
	/* Set register MCParam_reserved */
	void setMCParam_reserved(uint8_t value)
	{
		write(MCParam_reserved::__address, value, 8);
	}
	/* Get register MCParam_reserved */
	uint8_t getMCParam_reserved()
	{
		return read8(MCParam_reserved::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG IRQParam_1                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG IRQParam_1:
	 */
	struct IRQParam_1
	{
		static const uint16_t __address = 12;
		/* Bits Fifo_size: */
		/* Configures the size of the FIFO:  */
		struct Fifo_size
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
			static const uint8_t SIZE_16_BYTES = 0b00; // 16 bytes (d)
			static const uint8_t SIZE_32_BYTES = 0b01; // 32 bytes
			static const uint8_t SIZE_48_BYTES = 0b10; // 48 bytes
			static const uint8_t SIZE_64_BYTES = 0b11; // 64 bytes
		};
		/* Bits Fifo_thresh: */
		/*
		 * Number of bytes to be written in the FIFO to activate the
		 * Fifo_threshold interrupts
		 * Actual number of bytes = B + 1, where B is the value in the register.
		 * (d): B = 001111 => Number of bytes = 16
		 */
		struct Fifo_thresh
		{
			/* MODE rw */
			static const uint8_t dflt = 0b001111; // 6'b1111
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
		};
	};
	/* Set register IRQParam_1 */
	void setIRQParam_1(uint8_t value)
	{
		write(IRQParam_1::__address, value, 8);
	}
	/* Get register IRQParam_1 */
	uint8_t getIRQParam_1()
	{
		return read8(IRQParam_1::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG IRQParam_2                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG IRQParam_2:
	 */
	struct IRQParam_2
	{
		static const uint16_t __address = 13;
		/* Bits Rx_stby_irq_0: */
		/*
		 * IRQ_0 source in Rx and Standby modes:
		 * If Data_mode(1:0) = 00 (Continuous mode):
		 * 2'b00  Sync (d)
		 * 2'b01  RSSI
		 * 2'b10  Sync
		 * 2'b11  Sync
		 * If Data_mode(1:0) = 01 (Buffered mode):
		 * 2'b00  - (d)
		 * 2'b01  Write_byte
		 * 2'b10  /Fifoempty*
		 * 2'b11  Sync
		 * If Data_mode(1:0) = 1x (Packet mode):
		 * 2'b00  Payload_ready (d)
		 * 2'b01  Write_byte
		 * 2'b10  /Fifoempty*
		 * 2'b11  Sync or Adrs_match (the latter if address filtering is enabled)
		 * *also available in Standby mode (Cf sections 5.4.4 and 5.5.7)
		 * 
		 */
		struct Rx_stby_irq_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits Rx_stby_irq_1: */
		/*
		 * IRQ_1 source in Rx and Standby modes:
		 * If Data_mode(1:0) = 00 (Continuous mode):
		 * xx  -> DCLK
		 * If Data_mode(1:0) = 01 (Buffered mode):
		 * 2'b00  - (d)
		 * 2'b01  Fifofull*
		 * 2'b10  RSSI
		 * 2'b11  Fifo_threshold*
		 * If Data_mode(1:0) = 1x (Packet mode):
		 * 2'b00  CRC_ok (d)
		 * 2'b01  Fifofull*
		 * 2'b10  RSSI
		 * 2'b11  Fifo_threshold*
		 * *also available in Standby mode (Cf sections 5.4.4 and 5.5.7)
		 * 
		 */
		struct Rx_stby_irq_1
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00110000; // [4,5]
		};
		/* Bits Tx_start_irq_0: */
		/* Tx start condition and IRQ_0 source:  */
		struct Tx_start_irq_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			/*
			 * Start transmission when the number of bytes in FIFO is greater than or equal  to
			 * the  threshold  set  by  MCParam_Fifo_thresh  parameter  (Cf  section 5.2.2.3),
			 * IRQ_0 mapped to Fifo_threshold (d)
			 */
			static const uint8_t START_GT_THRESH = 0b0;
			static const uint8_t START_FIFO_NOT_EMPTY = 0b1; // Tx starts if FIFO is not empty, IRQ_0 mapped to /Fifoempty
		};
		/* Bits Tx_irq_1: */
		/*
		 * IRQ_1 source in Tx mode:
		 * If Data_mode(1:0) = 00 (Continuous mode):
		 * x  -> DCLK
		 * If Data_mode(1:0) = 01 (Buffered mode) or 1x (Packet mode):
		 */
		struct Tx_irq_1
		{
			/* MODE rw */
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t FIFO_FULL = 0b0; // Fifofull (Buffered mode or Packet mode) / DCLK (Continuous mode) (d)
			static const uint8_t TX_DONE = 0b1; // Tx_done (Buffered mode or Packet mode) / DCLK (Continuous mode)
		};
		/* Bits Fifofull: */
		/*
		 * Fifofull IRQ source
		 * Goes high when FIFO is full.
		 */
		struct Fifofull
		{
			/* MODE r */
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits Fifoempty: */
		/*
		 * Fifoempty IRQ source
		 * Goes low when FIFO is empty
		 */
		struct Fifoempty
		{
			/* MODE r */
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	/* Set register IRQParam_2 */
	void setIRQParam_2(uint8_t value)
	{
		write(IRQParam_2::__address, value, 8);
	}
	/* Get register IRQParam_2 */
	uint8_t getIRQParam_2()
	{
		return read8(IRQParam_2::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG IRQParam_3                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG IRQParam_3:
	 */
	struct IRQParam_3
	{
		static const uint16_t __address = 14;
		/* Bits Fifo_fill_method: */
		/* FIFO filling method (Buffered mode only):  */
		struct Fifo_fill_method
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t AUTO = 0b0; // Automatically starts when a sync word is detected (d)
			static const uint8_t MANUAL = 0b1; // Manually controlled by Fifo_fill §
		};
		/* Bits Fifo_fill: */
		/*
		 * FIFO filling status/control (Buffered mode only):
		 *   If Fifo_fill_method = ‘0’: (d)
		 * Goes high when FIFO is being filled (sync word has been detected)
		 * Writing ‘1’ clears the bit and waits for a new sync word (if Fifo_overrun_clr=0)
		 *   If Fifo_fill_method = ‘1’:
		 */
		struct Fifo_fill
		{
			/* MODE rwc */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t STOP = 0b0; // Stop filling the FIFO
			static const uint8_t START = 0b1; // Start filling the FIFO
		};
		/* Bits Tx_done: */
		/*
		 * Tx_done IRQ source
		 * Goes high when the last bit has left the shift register.
		 */
		struct Tx_done
		{
			/* MODE r */
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits Fifo_overrun_clr: */
		/*
		 * Goes high when an overrun error occurred.
		 * Writing a 1 anytime clears flag (if set) and launches a new Rx or Tx process
		 */
		struct Fifo_overrun_clr
		{
			/* MODE rwc */
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits Res: */
		/*
		 * (d): “0", should be set to “1".
		 * Note: “0" disables the RSSI IRQ source. It can be left enabled at any time,
		 * and the user can choose to map this interrupt to IRQ0/IRQ1 or not.
		 */
		struct Res
		{
			/* MODE rw */
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits RSSI_irq: */
		/*
		 * RSSI IRQ source:
		 * Goes high when a signal above RSSI_irq_thresh is detected
		 * Writing ‘1’ clears the bit
		 */
		struct RSSI_irq
		{
			/* MODE rwc */
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits PLL_locked: */
		/*
		 * 3.2.7. PLL status:
		 * The lock status can be read on bit IRQParam_PLL_lock, and must be cleared
		 * by writing a "1" to this same register.
		 */
		struct PLL_locked
		{
			/* MODE rwc */
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t NOT_LOCKED = 0b0; // not locked
			static const uint8_t LOCKED = 0b1; // locked
		};
		/* Bits PLL_lock_en: */
		/* 3.2.7. PLL_lock detect flag mapped to pin 23:  */
		struct PLL_lock_en
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t DISABLED = 0b0; // Lock detect disabled, pin 23 is HI
			static const uint8_t ENABLED = 0b1; // Lock detect enabled (d)
		};
	};
	/* Set register IRQParam_3 */
	void setIRQParam_3(uint8_t value)
	{
		write(IRQParam_3::__address, value, 8);
	}
	/* Get register IRQParam_3 */
	uint8_t getIRQParam_3()
	{
		return read8(IRQParam_3::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG IRQParam_4                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG IRQParam_4:
	 */
	struct IRQParam_4
	{
		static const uint16_t __address = 15;
		/* Bits RSSI_irq_thresh: */
		struct RSSI_irq_thresh
		{
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register IRQParam_4 */
	void setIRQParam_4(uint8_t value)
	{
		write(IRQParam_4::__address, value, 8);
	}
	/* Get register IRQParam_4 */
	uint8_t getIRQParam_4()
	{
		return read8(IRQParam_4::__address, 8);
	}
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG RXParam_1                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	/* REG RXParam_1:
	 */
	struct RXParam_1
	{
		static const uint16_t __address = 16;
		/* Bits PassiveFilt: */
		/* 3.4.4.1. Typical single sideband bandwidth of the passive low-pass filter. PassiveFilt  = 0000  65 kHz  */
		struct PassiveFilt
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1010; // 4'b1010
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
			static const uint8_t BW_82 = 0b001; // 82 kHz
			static const uint8_t BW_109 = 0b010; // 109 kHz
			static const uint8_t BW_137 = 0b011; // 137 kHz
			static const uint8_t BW_157 = 0b100; // 157 kHz
			static const uint8_t BW_184 = 0b101; // 184 kHz
			static const uint8_t BW_211 = 0b110; // 211 kHz
			static const uint8_t BW_234 = 0b111; // 234 kHz
			static const uint8_t BW_262 = 0b1000; // 262 kHz
			static const uint8_t BW_321 = 0b1001; // 321 kHz
			static const uint8_t BW_378 = 0b1010; // 378 kHz (d)
			static const uint8_t BW_414 = 0b1011; // 414 kHz
			static const uint8_t BW_458 = 0b1100; // 458 kHz
			static const uint8_t BW_514 = 0b1101; // 514 kHz
			static const uint8_t BW_676 = 0b1110; // 676 kHz
			static const uint8_t BW_987 = 0b1111; // 987 kHz
		};
		/* Bits ButterFilt: */
		/*
		 * 3.4.4.2. Sets the receiver bandwidth. For BW information please refer to sections 3.4.5 (FSK) and 3.4.6 (OOK).
		 * f_c  = f_0 + 200kHz * (f_xtal MHz/12.8MHz) * ((1 + Val(ButterFilt))/8)
		 * (d): “0011" => fC = 200 kHz
		 */
		struct ButterFilt
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0011; // 4'b11
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	/* Set register RXParam_1 */
	void setRXParam_1(uint8_t value)
	{
		write(RXParam_1::__address, value, 8);
	}
	/* Get register RXParam_1 */
	uint8_t getRXParam_1()
	{
		return read8(RXParam_1::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                   REG RXParam_PolypFilt_center                                    *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG RXParam_PolypFilt_center:
	 */
	struct RXParam_PolypFilt_center
	{
		static const uint16_t __address = 17;
		/* Bits PolypFilt_center: */
		/*
		 * 3.4.4.2. Central frequency of the polyphase filter (100kHz recommended):
		 * f  = 200kHz * (F_xtal MHz/12.8MHz) * ((1 + Val (PolypFilt _ center))/8)
		 * (d):“0011" => f0 = 100 kHz
		 */
		struct PolypFilt_center
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0011; // 4'b11
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1000; // 4'b1000
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	/* Set register RXParam_PolypFilt_center */
	void setRXParam_PolypFilt_center(uint8_t value)
	{
		write(RXParam_PolypFilt_center::__address, value, 8);
	}
	/* Get register RXParam_PolypFilt_center */
	uint8_t getRXParam_PolypFilt_center()
	{
		return read8(RXParam_PolypFilt_center::__address, 8);
	}
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG RXParam_3                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	/* REG RXParam_3:
	 */
	struct RXParam_3
	{
		static const uint16_t __address = 18;
		/* Bits PolypFilt_on: */
		/* Enable of the polyphase filter, in OOK Rx mode:  */
		struct PolypFilt_on
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t ON = 0b0; // off (d)
			static const uint8_t OFF = 0b1; // on
		};
		/* Bits Bitsync_off: */
		/* 5.2.3. Bit synchronizer: control in Continuous Rx mode:  */
		struct Bitsync_off
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t ON = 0b0; // on (d)
			static const uint8_t OFF = 0b1; // off §
		};
		/* Bits Sync_on: */
		/* 5.2.3. Sync word recognition:  */
		struct Sync_on
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t OFF = 0b0; // off (d)
			static const uint8_t ON = 0b1; // on
		};
		/* Bits Sync_size: */
		/* 5.2.3. Sync word size:  */
		struct Sync_size
		{
			/* MODE rw */
			static const uint8_t dflt = 0b11; // 2'b11
			static const uint8_t mask = 0b00011000; // [3,4]
			static const uint8_t SIZE_8_BITS = 0b00; // 8 bits
			static const uint8_t SIZE_16_BITS = 0b01; // 16 bits
			static const uint8_t SIZE_24_BITS = 0b10; // 24 bits
			static const uint8_t SIZE_32_BITS = 0b11; // 32 bits (d)
		};
		/* Bits Sync_tol: */
		/* 5.2.3. Number of errors tolerated in the Sync word recognition:  */
		struct Sync_tol
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000110; // [1,2]
			static const uint8_t NO_ERRORS = 0b00; // 0 error (d)
			static const uint8_t ONE_ERROR = 0b01; // 1 error
			static const uint8_t TWO_ERRORS = 0b10; // 2 errors
			static const uint8_t THREE_ERRORS = 0b11; // 3 errors
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	/* Set register RXParam_3 */
	void setRXParam_3(uint8_t value)
	{
		write(RXParam_3::__address, value, 8);
	}
	/* Get register RXParam_3 */
	uint8_t getRXParam_3()
	{
		return read8(RXParam_3::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                      REG RXParam_OOK_Thresh                                       *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG RXParam_OOK_Thresh:
	 */
	struct RXParam_OOK_Thresh
	{
		static const uint16_t __address = 19;
		/* Bits OOK_Thresh: */
		/*
		 * OOK fixed threshold or min threshold in peak mode. By default at 6dB.
		 * (d): “00000100" assuming 0.5dB RSSI step.
		 */
		struct OOK_Thresh
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000100; // 8'b100
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register RXParam_OOK_Thresh */
	void setRXParam_OOK_Thresh(uint8_t value)
	{
		write(RXParam_OOK_Thresh::__address, value, 8);
	}
	/* Get register RXParam_OOK_Thresh */
	uint8_t getRXParam_OOK_Thresh()
	{
		return read8(RXParam_OOK_Thresh::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG RXParam_RSSI                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/*
	 * REG RXParam_RSSI:
	 * 3.4.7. RSSI output, 0.5 dB / bit
	 * Note: READ-ONLY (not to be written)
	 */
	struct RXParam_RSSI
	{
		static const uint16_t __address = 20;
		/* Bits RSSI_val: */
		struct RSSI_val
		{
			/* MODE r */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register RXParam_RSSI */
	void setRXParam_RSSI(uint8_t value)
	{
		write(RXParam_RSSI::__address, value, 8);
	}
	/* Get register RXParam_RSSI */
	uint8_t getRXParam_RSSI()
	{
		return read8(RXParam_RSSI::__address, 8);
	}
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG RXParam_6                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	/* REG RXParam_6:
	 */
	struct RXParam_6
	{
		static const uint16_t __address = 21;
		/* Bits OOK_thresh_step: */
		/* Size of each decrement of the RSSI threshold in the OOK demodulator  */
		struct OOK_thresh_step
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
			static const uint8_t DECR_0_5_dB = 0b00; // 0.5 dB (d)       
			static const uint8_t DECR_1_0_dB = 0b01; // 1.0 dB             
			static const uint8_t DECR_1_5_dB = 0b10; // 1.5 dB             
			static const uint8_t DECR_2_0_dB = 0b11; // 2.0 dB             
			static const uint8_t DECR_3_0_dB = 0b100; // 3.0 dB
			static const uint8_t DECR_4_0_dB = 0b101; // 4.0 dB
			static const uint8_t DECR_5_0_dB = 0b110; // 5.0 dB
			static const uint8_t DECR_6_0_dB = 0b111; // 6.0 dB
		};
		/* Bits OOK_thresh_dec_period: */
		/* Period of decrement of the RSSI threshold in the OOK demodulator:  */
		struct OOK_thresh_dec_period
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00011100; // [2,3,4]
			static const uint8_t ONCE_IN_1 = 0b00; // once in each chip period (d)
			static const uint8_t ONCE_IN_2 = 0b01; // once in 2 chip periods
			static const uint8_t ONCE_IN_4 = 0b10; // once in 4 chip periods
			static const uint8_t ONCE_IN_8 = 0b11; // once in 8 chip periods
			static const uint8_t TWICE = 0b100; // twice in each chip period
			static const uint8_t FOUR_TIMES = 0b101; // 4 times in each chip period
			static const uint8_t EIGHT_TIMES = 0b110; // 8 times in each chip period
			static const uint8_t SIXTEEN_TIMES = 0b111; // 16 times in each chip period §
		};
		/* Bits OOK_avg_thresh_cutoff: */
		/*
		 * Cutoff  frequency  of  the  averaging  for  the  average  mode  of  the  OOK
		 * threshold in demodulator
		 */
		struct OOK_avg_thresh_cutoff
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t BR_OVER_8PI = 0b00; // fC   ≈ BR / 8.π  (d)
			static const uint8_t reserved_0 = 0b01; // 
			static const uint8_t reserved_1 = 0b10; // 
			static const uint8_t BR_OVER_32PI = 0b11; // fC   ≈ BR / 32.π
		};
	};
	/* Set register RXParam_6 */
	void setRXParam_6(uint8_t value)
	{
		write(RXParam_6::__address, value, 8);
	}
	/* Get register RXParam_6 */
	uint8_t getRXParam_6()
	{
		return read8(RXParam_6::__address, 8);
	}
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG SYNCParam                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	/* REG SYNCParam:
	 */
	struct SYNCParam
	{
		static const uint16_t __address = 22;
		/* Bits Sync_value: */
		/*
		 * 1st Byte of Sync word
		 * (d): “00000000"
		 */
		struct Sync_value
		{
			/* MODE rw */
			static const uint32_t dflt = 0b00000000000000000000000000000000; // 32'h0
			static const uint32_t mask = 0b11111111111111111111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31]
		};
	};
	/* Set register SYNCParam */
	void setSYNCParam(uint32_t value)
	{
		write(SYNCParam::__address, value, 32);
	}
	/* Get register SYNCParam */
	uint32_t getSYNCParam()
	{
		return read32(SYNCParam::__address, 32);
	}
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG TXParam                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	/* REG TXParam:
	 */
	struct TXParam
	{
		static const uint16_t __address = 26;
		/* Bits InterpFilt: */
		/*
		 * 3.3.6. Tx Interpolation filter cut off frequency:
		 * f_c = 200kHz * (F_xtal MHz/12.8MHz) * ((1 + Val(InterpFiltTx))/8)
		 * (d): “0111" => fC = 200 kHz
		 */
		struct InterpFilt
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0111; // 4'b111
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits Pout: */
		/* Tx output power (1 step ≈ 3 dB):  */
		struct Pout
		{
			/* MODE rw */
			static const uint8_t dflt = 0b001; // 3'b1
			static const uint8_t mask = 0b00001110; // [1,2,3]
			static const uint8_t P_12_5_dBm = 0b00; // 12.5 dBm
			static const uint8_t STEPS_1 = 0b01; // 12.5 dBm -1 step (d)
			static const uint8_t STEPS_2 = 0b10; // 12.5 dBm – 2 steps
			static const uint8_t STEPS_3 = 0b11; // 12.5 dBm – 3 steps
			static const uint8_t STEPS_4 = 0b100; // 12.5 dBm – 4 steps
			static const uint8_t STEPS_5 = 0b101; // 12.5 dBm – 5 steps
			static const uint8_t STEPS_6 = 0b110; // 12.5 dBm – 6 steps
			static const uint8_t STEPS_7 = 0b111; // 12.5 dBm – 7 steps
		};
		/* Bits TX_zero_if: */
		/* Set the transmitter in zero-if architecture in tx mode  */
		struct TX_zero_if
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t NORMAL = 0b0; // normal operation (d)
			static const uint8_t ZERO_IF = 0b1; // zero-if operation (first if is set to zero and frequency deviation is not used)
		};
	};
	/* Set register TXParam */
	void setTXParam(uint8_t value)
	{
		write(TXParam::__address, value, 8);
	}
	/* Get register TXParam */
	uint8_t getTXParam()
	{
		return read8(TXParam::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG OSCParam                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG OSCParam:
	 */
	struct OSCParam
	{
		static const uint16_t __address = 27;
		/* Bits Clkout_on: */
		/* Clkout control  */
		struct Clkout_on
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t DISABLED = 0b0; // Disabled
			static const uint8_t ENABLED = 0b1; // Enabled, Clk frequency set by Clkout_freq (d)
		};
		/* Bits Clkout_freq: */
		/*
		 * Frequency of the signal provided on CLKOUT:
		 * fclkout = f_xtal                     if Clkout_freq = “00000"
		 * fclkout = f_xtal / (2 ⋅ Clkout_freq) otherwise
		 * (d): 01111 (= 427 kHz)
		 */
		struct Clkout_freq
		{
			/* MODE rw */
			static const uint8_t dflt = 0b01111; // 5'b1111
			static const uint8_t mask = 0b01111100; // [2,3,4,5,6]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
		};
	};
	/* Set register OSCParam */
	void setOSCParam(uint8_t value)
	{
		write(OSCParam::__address, value, 8);
	}
	/* Get register OSCParam */
	uint8_t getOSCParam()
	{
		return read8(OSCParam::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG PKTParam_1                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG PKTParam_1:
	 */
	struct PKTParam_1
	{
		static const uint16_t __address = 28;
		/* Bits Manchester_on: */
		/* 5.5.6.1. Enable Manchester encoding/decoding:  */
		struct Manchester_on
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t OFF = 0b0; // off (d)
			static const uint8_t ON = 0b1; // on
		};
		/* Bits Payload_length: */
		/*
		 * If Pkt_format=0, payload length.
		 * If Pkt_format=1, max length in Rx, not used in Tx. (d): “0000000"
		 */
		struct Payload_length
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b01111111; // [0,1,2,3,4,5,6]
		};
	};
	/* Set register PKTParam_1 */
	void setPKTParam_1(uint8_t value)
	{
		write(PKTParam_1::__address, value, 8);
	}
	/* Get register PKTParam_1 */
	uint8_t getPKTParam_1()
	{
		return read8(PKTParam_1::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG PKTParam_2                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG PKTParam_2:
	 */
	struct PKTParam_2
	{
		static const uint16_t __address = 29;
		/* Bits Node_adrs: */
		/* Node’s local address for filtering of received packets. (d): 00h  */
		struct Node_adrs
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	/* Set register PKTParam_2 */
	void setPKTParam_2(uint8_t value)
	{
		write(PKTParam_2::__address, value, 8);
	}
	/* Get register PKTParam_2 */
	uint8_t getPKTParam_2()
	{
		return read8(PKTParam_2::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG PKTParam_3                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG PKTParam_3:
	 */
	struct PKTParam_3
	{
		static const uint16_t __address = 30;
		/* Bits Pkt_format: */
		/* Packet format:  */
		struct Pkt_format
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t FIXED_LENGTH = 0b0; // fixed length (d)
			static const uint8_t VARIABLE_LENGTH = 0b1; // variable length
		};
		/* Bits Preamble_size: */
		/* Size of the preamble to be transmitted:  */
		struct Preamble_size
		{
			/* MODE rw */
			static const uint8_t dflt = 0b10; // 2'b10
			static const uint8_t mask = 0b01100000; // [5,6]
			static const uint8_t SIZE_1_BYTE = 0b00; // 1 byte
			static const uint8_t SIZE_2_BYTES = 0b01; // 2 bytes
			static const uint8_t SIZE_3_BYTES = 0b10; // 3 bytes (d)
			static const uint8_t SIZE_4_BYTES = 0b11; // 4 bytes
		};
		/* Bits Whitening_on: */
		/* 5.5.6.2. Whitening/dewhitening process:  */
		struct Whitening_on
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t OFF = 0b0; // off (d)
			static const uint8_t ON = 0b1; // on
		};
		/* Bits CRC_on: */
		/* CRC calculation/check:  */
		struct CRC_on
		{
			/* MODE rw */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t OFF = 0b0; // off
			static const uint8_t ON = 0b1; // on (d)
		};
		/* Bits Adrs_filt: */
		/* Address filtering of received packets:  */
		struct Adrs_filt
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000110; // [1,2]
			static const uint8_t OFF = 0b00; // off (d)
			static const uint8_t NODE_ADRS = 0b01; // Node_adrs accepted, else rejected.
			static const uint8_t NODE_ADRS_AND_00 = 0b10; // Node_adrs & 0x00 accepted, else rejected.
			static const uint8_t NODE_ADRS_AND_00_AND_FF = 0b11; // Node_adrs & 0x00 & 0xFF accepted, else rejected.
		};
		/* Bits CRC_status: */
		/* CRC check result for current packet (READ ONLY):  */
		struct CRC_status
		{
			/* MODE r */
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t FAIL = 0b0; // Fail
			static const uint8_t PASS = 0b1; // Pass §
		};
	};
	/* Set register PKTParam_3 */
	void setPKTParam_3(uint8_t value)
	{
		write(PKTParam_3::__address, value, 8);
	}
	/* Get register PKTParam_3 */
	uint8_t getPKTParam_3()
	{
		return read8(PKTParam_3::__address, 8);
	}
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG PKTParam_4                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	/* REG PKTParam_4:
	 */
	struct PKTParam_4
	{
		static const uint16_t __address = 31;
		/* Bits CRC_autoclr: */
		/* FIFO auto clear if CRC failed for current packet:  */
		struct CRC_autoclr
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t ON = 0b0; // on (d)
			static const uint8_t OFF = 0b1; // off §
		};
		/* Bits Fifo_stby_access: */
		/* FIFO access in standby mode:  */
		struct Fifo_stby_access
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t WRITE = 0b0; // Write (d)
			static const uint8_t READ = 0b1; // Read
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
		};
	};
	/* Set register PKTParam_4 */
	void setPKTParam_4(uint8_t value)
	{
		write(PKTParam_4::__address, value, 8);
	}
	/* Get register PKTParam_4 */
	uint8_t getPKTParam_4()
	{
		return read8(PKTParam_4::__address, 8);
	}
};
