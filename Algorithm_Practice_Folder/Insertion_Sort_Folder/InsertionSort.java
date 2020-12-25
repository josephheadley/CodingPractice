package CS_136_Folder.Algorithm_Practice_Folder.Insertion_Sort_Folder;

import java.util.Arrays;
import java.util.Random;

public class InsertionSort {
    void insertionsort(int[] arr){
        int num = arr.length;
        for(int i = 1; i < num; ++i){
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && key < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    public static void main(String args[]){
        InsertionSort object = new InsertionSort();

        Random rd = new Random();
        int number = Integer.parseInt(args[0]);
        int number2 = Integer.parseInt(args[1]);
        int[] randarray = new int[number2];
        for(int i = 0; i < number2; i++){
            randarray[i] = rd.nextInt(number);
        }
        System.out.println("\nRandomized Array:");
        System.out.println(Arrays.toString(randarray));

        long start = System.nanoTime();
        object.insertionsort(randarray);
        long end = System.nanoTime();
        double time_elasped = (double)(end - start)/1000;

        System.out.println("\nSelection Sorted array:");
        System.out.println(Arrays.toString(randarray));
        System.out.println("\nTime elasped while sorting (in microseconds):");
        System.out.println(time_elasped);
        System.out.println("\n");
    }
}