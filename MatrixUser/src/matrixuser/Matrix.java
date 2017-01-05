package matrixuser;
import java.util.Random;

/**
 *
 * @author NIKO
 */
public class Matrix {
    private int[][] data;
    int numRows;
    int numColumns;
    
    /* Constructor */
    public Matrix(int r, int c) {
        data = new int[r][c];
        numRows = r;
        numColumns = c;    
    }
    
    /* fill every element in data with a given value */
    public void fill(int value) {
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                data[i][j] = value;
            }
        }
    }
    
    /* fill an individual cell with a value */
    public void fillCell(int value, int row, int column) {
        data[row][column] = value;
    }
    
    /* Randomly fill the matrix with values at each cell.  For
       simplicity, we will fill with the matrix with single
       digit numbers.
    */
    public void fillRandomly() {
        Random rand = new Random();
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                int value = rand.nextInt(10);
                data[i][j] = value;
            }
        }
    }
    
    /* get the number of rows */
    public int getNumRows() { 
        return numRows; 
    }
    /* get the number of columns */
    public int getNumColumns() { 
        return numColumns; 
    }
    
    /* get the value at a particular cell */
    public int getCellValue(int row, int column) {
        return data[row][column];
    }
    
    /* Add two matrices and return a matrix.  Only allow
       the additions to occur if they have the same dimensions.
    */
    public static Matrix add(Matrix a, Matrix b) {
        if (a.getNumRows() != b.getNumRows() ||
                a.getNumColumns() != b.getNumColumns())
            throw new IllegalArgumentException("Error: Cannot add"
                    + " Matrices with different dimenions");
        
        int rows = a.getNumRows();
        int columns = a.getNumColumns();
        Matrix newMatrix = new Matrix(rows, columns);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                int value = a.getCellValue(i, j) + b.getCellValue(i, j);
                newMatrix.fillCell(value, i, j);
            }
        }
        
        return newMatrix;
    }
    
    /* return a new matrix that is the product of two
       matrices.  Check to make sure that the number of columns
       in a is the same as the number of rows in b.
    */
    public static Matrix multiply(Matrix a, Matrix b) {
        if (a.numColumns != b.numRows)
            throw new IllegalArgumentException(
                "Exception: dimensions of the matrices do"
                        + "not allow matrix multiplication");
        
        Matrix newMatrix = new Matrix(a.numRows, b.numColumns);
        int rows = newMatrix.numRows;
        int columns = newMatrix.numColumns;
        
        for (int i = 0; i < rows; i++) {
            int[] row = MatrixHelper.getRow(a.data, i);
            for (int j = 0; j < columns; j++) {
                /* Get the current row from a and the current column from b,
                   each as their own array
                */
                int[] column = MatrixHelper.getColumn(b.data, j);
                /* take the dot product of the two days, and push that
                   value into the newMatrix as an element at row i
                   and column j*/
                int dp = MatrixHelper.dotProduct(row, column);
                newMatrix.fillCell(dp, i, j);
            }
        }
        
        return newMatrix;
    }
    
    /* return the contents of the matrix as a string */
    @Override
    public String toString() {
        String result = "";
        /* add each element to result string
           by converting it from int to string
        */
        for (int i = 0; i < numRows; i++) {
            result += "|";
            for (int j = 0; j < numColumns; j++) {
                int nextValue = getCellValue(i, j);
                //result += nextValue + " ";
                result += String.format("%4d", nextValue);
            }
            // add a new line after each row
            // except for the last row
            result += (i < numRows - 1) ? "   |\n" : "   |";
        }
        
        return result;
    }
}