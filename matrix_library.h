#include "project.h"
#include "stdbool.h"
#include "string.h"
/*Variables to matrix if your do it in protoboard*/
unsigned int rows =0;
unsigned int cols=0; 
char key;
/*--------------------------------------------------*/
/*Variables to matrix if you do it in UPY Developer Board */
unsigned char rows1=0, cols1=0, key1=0;
char c_key;
/*--------------------------------------------------*/

char keyLine[255]; //Cuando el user press Enter se guarda el String
char keyLine_temp[255]; //Almacena los datos que va press el user mientras no pressiona enter. Si el usuar press Enter esto se borra!
char keyLine_Security[255]; //Almacena los datos que va press el user como un asterisco mientras no pressiona enter. Si el usuar press Enter esto se borra!
char temp[255];
int c_length=0;

/*****************************************************************************\
 * Function:    keypad_scan(void)
 * Input:       void
 * Returns:     This function return in 'key' variable (global char variable) e.g. if(key=='1'){//someCode}
 * Description: Use just 'keypad_scan' function instead of 'keypad_scanUDB' if your matrix is connected 
                to a protoboard. 
\*****************************************************************************/
                
/*****************************************************************************\
 * Function:    keypad_scanUDB(void)
 * Input:       void
 * Returns:     This function return in 'c_key' variable (global char variable) e.g. if(c_key=='1'){//someCode}
 * Description: Use 'keypad_scanUDB' function instead of keypad_scan if your matrix is connected to
                UPY Developer Board.

\*****************************************************************************/

/*****************************************************************************\
 * Function:    MatrixCheckLoop( component, modo)
 * Input:       component: This option, you need to put the component where the output will be printed ("LCD"/"UART")
                modo: choose the modality of your physical matrix connection. If it connected in a protoboard? So, use keypad_scan, Nevertheless, if this is connected 
                in a special proto by UPY's Emb engineers you will need to use keypad_scanUDB

 * Returns:     void because is a loop!  But, it will print in component ("LCD"/"UART") the key pressed!
 * Description: Use without interruption just to check the functionality of matricial componet!

\*****************************************************************************/

/*****************************************************************************\ "#"--"\n"
 * Function:    key_scanLine(ENTER, Longitud maxima, MODO)
 * Input:       ENTER: it's the final character of the message
                MODO: it's the modality of your physical matrix connection
 * Returns:     return in keyLine a str when user press enter (#/D/C)
 * Description: Use this function when you need to get a message from Matrix.

\*****************************************************************************/


void keypad_scan(void){
    
    Matrix_Write(0xF0); /* 00001111 */    /* ***** 11110000 */
    //cols = Matrix_Read();
    rows = Matrix_Read();
    //LCD_Position(0,0);
    //LCD_PrintHexUint16(rows);
    Matrix_Write(0xF); /* 11110000 */ /* ******00001111 */ 
    //rows = Matrix_Read();
    cols = Matrix_Read();
    //LCD_Position(1,0);
    //LCD_PrintHexUint16(cols);
    
    ///LCD_Position(1,7);
    ///LCD_PrintHexUint16(rows&cols);
    
    switch(rows & cols)
    {               /* Binary Numbers */
        case 0x15: /* 0b00010001 */
            key = 'D';
            break;
        case 0x16: /* 0b00010010 */
            //key = 'C';
            key = '#';
            break;
        case 0x14:  /* 0b00010100 */
            //key = 'B';
            key = '0';
            break;
        case 0x1C: /* 0b00011000 */
//            key = 'A';
            key = '*';
            break;
        case 0x25: /*  */ 
//            key = '#';
            key = 'C';
            break;
        case 0x26: 
//            key = '9';
            key = '9';
            break;
        case 0x24:
//            key = '6';
            key = '8';
            break;
        case 0x2C: 
            //key = '3';
            key = '7';
            break;        
        case 0x45: 
            //key = '0';
            key = 'B';
            break;  
        case 0x46: 
//            key = '8';
            key = '6';
            break;  
        case 0x44: 
            key = '5';
            break;  
        case 0x4C: 
            //key = '2';
            key = '4';
            break;  
        case 0x85: 
//            key = '*';
            key = 'A';
            break;          
        case 0x86:
//            key = '7';
            key = '3';
            break;
        case 0x84:
//            key = '4';
            key = '2';
            break; 
        case 0x8C:
            key = '1';
            break;

    }
}


void keypad_scanUDB(void){

    //////////////////////////////// LECTURA DE BALORES.
    Matrix_Write(0b00001111);
    rows1=Matrix_Read();
        
    Matrix_Write(0b11110000);
    cols1=Matrix_Read();
    
    key1=cols1&rows1;
    
    switch(key1){
        
        case 152: //1
           c_key='1';      
            break;
        
        case 148: //
            c_key='2';    
            break;
        case 146: //3
            c_key='3';        
            break;
        case 145: //A
            c_key='A';        
            break;
        case 88: //4
            c_key='4';
            break;
        case 84: //5
            c_key='5';   
            break;
           
        case 82: //6
            c_key='6';     
            break;
            
        case 81: //B
            c_key='B';    
            break;
            
        case 56: //7
            c_key='7'; 
            break;
        
        case 52: //8
            c_key='8';
            break;
           
        case 50: //9
            c_key='9';     
            break;
            
        case 49: //C
            c_key='C';     
            break;
            
            
        case 24: //*
            c_key='*'; 
            break;
        
        case 20: //0
            c_key='0';   
            break;
           
        case 18: //#
            c_key='#';    
            break;
            
        case 17: //D
            c_key='D';     
            break;
            
    }
 
}
// unaFuncion(otraFuncion())
// int luis = 23;
// int* dirLuis = &luis;
// printf("%i",*dirLuis)----> 23
// *dirLuis = 25;
// printf("%i",luis)----> 25
// sum(&luis, 1)---- 26
// printf("%i",luis)----> 25
/// MatrixCheckLoop("UART", keypad_scanUDB) ///

void MatrixCheckLoop(const char* componet, void (*ptrFunc)()){
    if(strcmp(componet,"UART")==0){
        while(true){   
            //someCode
        }
    }else if(strcmp(componet,"LCD")==0){
        while(true){
            LCD_Position(0,0);
            ptrFunc();
            LCD_PutChar(key);
            LCD_Position(1,0);
            LCD_PutChar(c_key);
            
        }
    }
}

void key_scanLine(char enter,int length, void (*func)()){
    func(); //Puede ser el UDB o el normal.
    if((key ==enter)|| (c_key == enter)){
        strcpy(keyLine,keyLine_temp);
        strcpy(keyLine_temp,"");
        strcpy(keyLine_Security,"");
        key=' '; c_key=' ';
        c_length =0;    
    }

    if(c_length<=length){
        
        if(((key > ' ')|| (c_key > ' ')) && ((key != enter)|| (c_key != enter)) ){
            strcat(keyLine_temp,&key); //strcat(keyLine_temp,&c_key);
            strcat(keyLine_Security,"*");
            
        };
        c_length++;
    }
}


void ClearKeyLine(){
    strcpy(keyLine,"");
}

