/*************************************************************/
/*       UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE         */
/*   DEPARTAMENTO DE ENGENHARIA DE COMPUTAÇÃO E AUTOMAÇÃO    */
/*							     */
/*   DRIVER DO BRAÇO ROBÓTICO LYNX AL5D PARA A PORTA SERIAL  */
/*							     */
/*   DESENVOLVEDORES:					     */
/*	- ENG. M.SC. DESNES AUGUSTO NUNES DO ROSÁRIO	     */
/*	- ENG. DANILO CHAVES DE SOUSA ICHIHARA		     */
/*************************************************************/

#ifndef _UFRN_AL5D_H_
#define _UFRN_AL5D_H_

	#include <stdio.h>
	#include <string.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <termios.h>
	#include <math.h>

	#define BUFSIZE 1024

	// Dimensões dos braços ( mm ) //
	// REVER		       //
	/*
	#define BASE_HGT 67.31      //altura da baset 2.65"
	#define HUMERUS 146.05      //ombro-para-cotovelo 5.75"
	#define ULNA 187.325        //cotovelo-para-punho 7.375"
	#define GRIPPER 100.00      //gripper (incl.heavy duty wrist rotate mechanism) length 3.94"
	 
	#define ftl(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))  //float to long conversion
	*/

	// SERVOS //

	// Servo da base HS-485HB //
	#define BAS_SERVO 0
	#define BAS_MIN 500
	#define BAS_MAX	2380

	// Servo do ombro HS-805BB //
	#define SHL_SERVO 1
	#define SHL_MIN 1200
	#define SHL_MAX 2000

	// Servo do cotovelo HS-755HB//
	#define ELB_SERVO 2
	#define ELB_MIN 1100
	#define ELB_MAX 2100

	// Servo do punho HS-645MG //
	#define WRI_SERVO 3
	#define WRI_MIN 500
	#define WRI_MAX	2500
	
	// Servo da garra HS-322HD //
	#define GRI_SERVO 4
	#define GRI_MIN 1300
	#define GRI_MAX 2400

	int configurar_porta(int);
	int abrir_porta(void);
	int enviar_comando(char*,int);

	unsigned int trava(unsigned int canal, unsigned int pos);

	void fechar_porta(int);
	void ufrn_header(void);

#endif

