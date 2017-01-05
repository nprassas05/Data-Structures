/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package matrixuser;

/**
 *
 * @author ELENA
 */
public class MatrixUser {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Matrix a = new Matrix(2, 2);
        Matrix b = new Matrix(2, 2);
        a.fillRandomly();
        b.fillRandomly();
        
        System.out.println("Matrix A:\n" + a.toString());
        System.out.println("Matrix B:\n" + b.toString());
        
        Matrix sum = Matrix.add(a, b);
        System.out.println("Matrix Sum:\n" + sum.toString());
        
        Matrix product = Matrix.multiply(a, b);
        System.out.println("Matrix Product:\n" + product.toString());
    }
    
}
