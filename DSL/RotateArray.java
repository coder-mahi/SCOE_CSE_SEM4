import java.util.Arrays;

public class RotateArray{
    public static void rotate(int[] arr,int d){
        int n = arr.length;
        d = d%n;
        if(arr.length == 0 || d>n){
            return;
        }

        reverse(arr,0,d-1);
        reverse(arr,d,n-1);
        reverse(arr,0,n-1);
    }
    public static void reverse(int[] arr,int left,int right){
        while(left<right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    public static void main(String[] args) {
        int[] arr = {10,20,30,40,50};
        int d = 3;
        System.out.println("Before rotate :> "+Arrays.toString(arr));
        rotate(arr, d);
        System.out.println("After rotate :> "+Arrays.toString(arr));
    }
}