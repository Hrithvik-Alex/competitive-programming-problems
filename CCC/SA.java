/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sa;
import java.util.*;
/**
 *
 * @author azumnanji
 */
public class SA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);
        
        int inputnumber = sc.nextInt();
        String stringnumber = Integer.toString(inputnumber);
        
        int number =0;
        int output1 [] = new int [stringnumber.length()];
        int output [] = new int [stringnumber.length()];
        int multiplier = 0;
        int multiplier1 = 0;
        String hello = "";
        
        for (int i = 0; i < stringnumber.length(); i ++)
        {
            hello = Character.toString(stringnumber.charAt(i));
            output [i] = Integer.parseInt(hello);
        }
        
        for (int i = 0; i < stringnumber.length(); i++)
        {
            
            if (output [i]!= 0)
            {
                multiplier1 = (stringnumber.length() - 1 - i);
                multiplier = (int) Math.pow(10, multiplier1 );       
                output1 [i] = output[i]*multiplier;
            }
        }
        
        for (int i = 0; i < stringnumber.length(); i++)
        {
        
            if ( i == stringnumber.length() - 1)
            {
                if (output1[i] != 0)
                {
                    System.out.print(output1[i]);
                }
            }
            else
            {
                if (output1[i] != 0)
                {
                    System.out.print(output1 [i] + " + ");
                }
            }
        }
               
    }
    
}
