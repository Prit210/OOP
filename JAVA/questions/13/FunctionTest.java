//Question 13



interface Function {
    int evaluate(int x);
}

class Half implements Function {

    @Override
    public int evaluate(int x) {
        return x / 2;
    }
}

public class FunctionTest {

    public static int[] applyFunctionToArray(int[] arr, Function function) {
        int[] result = new int[arr.length];
        
        for (int i = 0; i < arr.length; i++) {
            result[i] = function.evaluate(arr[i]);
        }
        
        return result;
    }

    public static void main(String[] args) {
        int[] numbers = {10, 20, 30, 40, 50};
        Half halfFunction = new Half();
        
        int[] halvedNumbers = applyFunctionToArray(numbers, halfFunction);
        
        System.out.print("Halved numbers: ");
        for (int num : halvedNumbers) {
            System.out.print(num + " ");
        }
    }
}
