//Program of Implementation of Huffman Tree

import java.util.Comparator;
import java.util.PriorityQueue;

class Node {
    int data;
    char c;
    Node left;
    Node right;
}

class NodeComparator implements Comparator<Node> {
    public int compare(Node m, Node n) {
        return m.data - n.data;
    }
}

public class Huffman {
    public static void printCode(Node root, String s) {
        if (root.left == null && root.right == null && Character.isLetter(root.c)) {
            System.out.println(root.c + ":" + s);
            return;
        }
        if (root.left != null) {
            printCode(root.left, s + "0");
        }
        if (root.right != null) {
            printCode(root.right, s + "1");
        }
    }

    public static void main(String args[]) {
        int size = 5;

        char charArray[] = { 'a', 'b', 'c', 'd', 'e' };
        int intArray[] = { 5, 3, 4, 2, 7 };
        PriorityQueue<Node> q = new PriorityQueue<Node>(size, new NodeComparator());

        
        for (int i = 0; i < size; i++) {
            Node nn = new Node();
            nn.c = charArray[i];
            nn.data = intArray[i];
            nn.left = null;
            nn.right = null;
            q.add(nn);
        }

        Node root = null;

        while (q.size() > 1) {
            Node m = q.poll();
            Node n = q.poll();

            Node p = new Node();
            p.data = m.data + n.data;
            p.c = '-'; 
            p.left = m;
            p.right = n;
            root = p;

            q.add(p);
        }
        root = q.poll();
        printCode(root, "");
    }
}