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
// </editor-fold>

#endif	/* STORAGE_H */

