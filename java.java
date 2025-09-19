import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Массив
        System.out.println("Массив:");
        int[] arr = {10, 20, 30};
        System.out.println(Arrays.toString(arr));

        // Список
        System.out.println("\nСписок:");
        ArrayList<String> list = new ArrayList<>();
        list.add("яблоко");
        list.add("банан");
        System.out.println(list);

        // Стек
        System.out.println("\nСтек:");
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        System.out.println("Верхний: " + stack.peek());
        stack.pop();
        System.out.println("Теперь верхний: " + stack.peek());
    }
}
