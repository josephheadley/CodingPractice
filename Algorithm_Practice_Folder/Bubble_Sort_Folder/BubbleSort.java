package CS_136_Folder.Algorithm_Practice_Folder.Bubble_Sort_Folder;

import java.util.Arrays;
import java.util.Random;

/*
This Java program, as well as all further Java Sorting Algorithm programs,
use two command line arguments to run the sorting algorithm.

The first argument determines the maximum value an element in this array 
can have and the second argument determines the size of the randomized array. 

An example of how to run this program in the terminal would be:

% java BubbleSort.java 100 10 

This would produce and sort a random array of 10 elements with a 
maximum possible value of 100.
*/

public class BubbleSort{
    void bubblesort(int arr[]){
        int num = arr.length;
        for (int i = 0; i < num-1; i++){
            for (int j = 0; j < num-i-1; j++){
                if (arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    
    void optbubblesort(int arr[], int num) {
        boolean swapped;
        for (int i = 0; i < num - 1; i++) {
            swapped = false;
            for (int j = 0; j < num - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (swapped == false) {
                break;
            }
        }
    }

    public static void main(String args[]) {
        BubbleSort object = new BubbleSort();

        int number = Integer.parseInt(args[0]);
        int number2 = Integer.parseInt(args[1]);
        Random rd = new Random();
        int[] randarray = new int[number2];
        int[] copyrandarray = new int[number2];

        for (int i = 0; i < number2; i++) {
            randarray[i] = rd.nextInt(number);
            copyrandarray[i] = randarray[i];
        }

        System.out.println("\nRandomized Array:");
        System.out.println(Arrays.toString(randarray));

        long start = System.nanoTime();
        object.bubblesort(randarray);
        long end = System.nanoTime();
        double time_elasped = (double) (end - start) / 1000;

        System.out.println("\nBubble Sorted array:");
        System.out.println(Arrays.toString(randarray));
        System.out.println("\nTime elasped while sorting (in microseconds):");
        System.out.println(time_elasped);

        BubbleSort object2 = new BubbleSort();

        System.out.println("\nCopy of Randomized Array:");
        System.out.println(Arrays.toString(copyrandarray));

        long start2 = System.nanoTime();
        object2.optbubblesort(copyrandarray, number2);
        long end2 = System.nanoTime();
        double time_elasped2 = (double)(end2 - start2)/1000;

        System.out.println("\nOptimized Bubble Sorted array:");
        System.out.println(Arrays.toString(copyrandarray));
        System.out.println("\nTime elasped while sorting (in microseconds):");
        System.out.println(time_elasped2);
        System.out.println("\n");
    }
}