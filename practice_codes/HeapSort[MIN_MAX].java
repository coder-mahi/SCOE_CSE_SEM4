import java.util.Arrays;
import java.util.Scanner;

public class HeapSortCombined {

    public void maxHeapSort(int[] array) {
        int n = array.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(array, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            swap(array, 0, i);
            maxHeapify(array, i, 0);
        }
    }

    private void maxHeapify(int[] array, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && array[left] > array[largest]) {
            largest = left;
        }

        if (right < n && array[right] > array[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(array, i, largest);
            maxHeapify(array, n, largest);
        }
    }

    public void minHeapSort(int[] arr) {
        int n = arr.length;

        for (int i = (n / 2) - 1; i >= 0; i--) {
            minHeapify(arr, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            swap(arr, 0, i);
            minHeapify(arr, i, 0);
        }
    }

    public void minHeapify(int arr[], int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest]) {
            smallest = left;
        }

        if (right < n && arr[right] < arr[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(arr, i, smallest);
            minHeapify(arr, n, smallest);
        }
    }

    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Heap Sort Options:");
        System.out.println("1. Max Heap Sort");
        System.out.println("2. Min Heap Sort");
        System.out.print("Enter your choice (1 or 2): ");
        int choice = sc.nextInt();

        System.out.println("Enter the size of the Array:");
        int size = sc.nextInt();

        int[] array = new int[size];

        System.out.println("Enter " + size + " integers:");
        for (int i = 0; i < size; i++) {
            array[i] = sc.nextInt();
        }

        System.out.println("Original array: " + Arrays.toString(array));

        HeapSortCombined heapSort = new HeapSortCombined();

        switch (choice) {
            case 1:
                heapSort.maxHeapSort(array);
                System.out.println("Max Heap Sorted array: " + Arrays.toString(array));
                break;
            case 2:
                heapSort.minHeapSort(array);
                System.out.println("Min Heap Sorted array: " + Arrays.toString(array));
                break;
            default:
                System.out.println("Invalid choice. Please enter 1 for Max Heap Sort or 2 for Min Heap Sort.");
        }

        sc.close();
    }
}


//Output :
1.
Heap Sort Options:
1. Max Heap Sort
2. Min Heap Sort
Enter your choice (1 or 2): 1
Enter the size of the Array:
5
Enter 5 integers:
12
5
2
488
95
Original array: [12, 5, 2, 488, 95]       
Max Heap Sorted array: [2, 5, 12, 95, 488]

2.
Heap Sort Options:
1. Max Heap Sort
2. Min Heap Sort
Enter your choice (1 or 2): 2
Enter the size of the Array:
5
Enter 5 integers:
6542
1
8
13
875
Original array: [6542, 1, 8, 13, 875]
Min Heap Sorted array: [6542, 875, 13, 8, 1]