import java.io.*;
import java.util.*;

class Solution {
  private static long sumOf1ToN(long n) {
    return (n * (n + 1)) / 2;
  }

  private static long calcSumOfMultiplesOf3Or5(long n) {
    long multi3Count = (n - 1) / 3;
    long multi5Count = (n - 1) / 5;
    long multi15Count = (n - 1) / 15;

    long multi3Sum = 3 * sumOf1ToN(multi3Count);
    long multi5Sum = 5 * sumOf1ToN(multi5Count);
    long multi15Sum = 15 * sumOf1ToN(multi15Count);

    return (multi3Sum + multi5Sum - multi15Sum);
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    while(t-- > 0) {
      int n = in.nextInt();
      System.out.println(calcSumOfMultiplesOf3Or5(n));
    }
  }
}
