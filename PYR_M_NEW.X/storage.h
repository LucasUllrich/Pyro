/* 
 * File:   storage.h
 * Author: Lucas
 *
 * Created on 14. April 2016, 13:11
 */

#ifndef STORAGE_H
#define	STORAGE_H
#include "main.h"

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">
void Save_Data(unsigned int store, unsigned char store_address);
unsigned int Read_Data(unsigned char read_address);
void Load_Data(void);
void Del_Data(void);
// </editor-fold>


/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="variables">
unsigned char string_load[3];
unsigned char string_delete[3];
// </editor-fold>
#endif	/* STORAGE_H */

