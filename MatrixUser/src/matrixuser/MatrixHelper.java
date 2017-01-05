/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package matrixuser;

/**
 *
 * @author NIKO
 * 
 * the following MatrixHelper class contains a few useful methods that are used
 * for certain arithmetic operations in the Matrix class.  They are written in a
 * separate class because the methods in the Matrix class that use these methods
 * would be too jumbled up otherwise.  The methods are protected since they are
 * really only meant for use by the Matrix class.
 */
public class MatrixHelper {
    /* return the dot product of two int arrays */
    protected static int dotProduct(int[] a, int[] b) {
        if (a.length != b.length)
            throw new IllegalArgumentException("Exception: cannot take "
                    + "dot product of arrays with different lengths");
        int result = 0;
        for (int i = 0; i < a.length; i++)
            result += (a[i] * b[i]);
        
        return result;
    }
    
    /* return an array of a single row in a 2D array. 
       Zero indexed, so that an argument of 0
       means return the first row.
    */
    protected static int[] getRow(int[][] array, int rowNum) {
        int[] row = new int[array[0].length];
        for (int i = 0; i < array[0].length; i++) {
            row[i] = array[rowNum][i];
        }
        
        return row;
    }
    
    /* return an array containing a single column
       of a 2D array.  Zero indexed, so that an argument of 
       0 returns the first column.
    */
    protected static int[] getColumn(int[][] array, int columnNum) {
        int numRows = array.length;
        int[] column = new int[numRows];
        
        for (int i = 0; i < numRows; i++) {
            column[i] = array[i][columnNum];
        }
        
        return column;
    }
}
