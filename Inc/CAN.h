/**
 * This is the header file for the CAN driver.
 * 
 * The CAN controller configured will have no ID filters, and the
 * bit rate is set to 400KBS. 
 *
 * Polling will be required by the user, since the functions executed when CAN 
 * messages are received are too complex and long, and will not be suitable to
 * be placed in a interrupt handler (the alternative is to have the interrupt 
 * set a valid bit and poll that bit in the main loop. Unfortunately, clearing
 * the interrupt mask means setting the pending number of CAN messages to 0, 
 * which means, depending on the rate of messages being received, some messages
 * will be dropped.)
 *
 * Note: Please define the following fields in the main file 
 * (or any file that will include this header file):
 * - CAN_msg_t CAN_rx_msg
 * - CAN_msg_t CAN_tx_msg
 */

//#include "stm32f1xx_hal_can.h"
#include "stm32f1xx_hal.h"

#ifndef CAN_H
#define CAN_H

typedef struct
{
	uint16_t id;
	uint8_t  data[8];
	uint8_t  len;
} CAN_msg_t;

/**
 * Initializes the CAN controller with bit rate of [].
*/
void CANInit(void);
 
/**
 * @brief Sets up the struct with the filters information
*/
void CAN_Set_Filters(CAN_FilterTypeDef* fltr);
/**
 * Decodes CAN messages from the data registers and populates a 
 * CAN message struct with the data fields.
 * 
 * @preconditions A valid CAN message is received
 * @params CAN_rx_msg - CAN message struct that will be populated
 * 
*/
//void CANReceive(CAN_msg_t* CAN_rx_msg);



/**
 * Encodes CAN messages using the CAN message struct and populates the 
 * data registers with the sent.
 * 
 * @params CAN_rx_msg - CAN message struct that will be populated
 * 
*/
//void CANSend(CAN_msg_t* CAN_tx_msg); //NOT USED

/**
 * @brief Transmit CAN messages
 * @param msg is a pointer to a uint8_t array with length len
 * @param len is the length of the array (unsigned int)
 * @note the array must be between 1 and 8 bytes long
 */
void CAN_Tx(CAN_HandleTypeDef* hcan, CAN_TxHeaderTypeDef* TxHeader, uint32_t* TxMailbox, uint8_t* msg, unsigned int len);
/**
 * Returns whether there are CAN messages available.
 *
 * @returns If pending CAN messages are in the CAN controller
 *
 */
 //uint8_t CANMsgAvail(void);
/*
 extern CAN_msg_t CAN_rx_msg;  // Holds receiving CAN messages
 extern CAN_msg_t CAN_tx_msg;  // Holds transmitted CAN messagess
*/
#endif
