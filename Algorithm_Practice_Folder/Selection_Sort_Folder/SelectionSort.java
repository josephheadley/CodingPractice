package CS_136_Folder.Algorithm_Practice_Folder.Selection_Sort_Folder;

import java.util.Arrays;
import java.util.Random;

public class SelectionSort {
    void selectionsort(int arr[]){
        int num = arr.length;
        for(int i = 0; i < num-1; i++){
            int min_idx = i;
            for(int j = i+1; j < num; j++){
                if(arr[min_idx] > arr[j]){
                    min_idx = j;
                }
            }
            int tmp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = tmp;
        }
    }
    public static void main(String args[]){
        SelectionSort object = new SelectionSort();
        
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
        object.selectionsort(randarray);
        long end = System.nanoTime();
        double time_elasped = (double)(end - start)/1000;

        System.out.println("\nSelection Sorted array:");
        System.out.println(Arrays.toString(randarray));
        System.out.println("\nTime elasped while sorting (in microseconds):");
        System.out.println(time_elasped);
        System.out.println("\n");
    }
}