import java.util.Scanner;

public class Main {
    static int[] win = new int[6];
    static int[] draw = new int[6];
    static int[] lose = new int[6];
    static boolean isPossible;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 4; i++) {
            isPossible = true;
            for (int j = 0; j < 6; j++) {
                win[j] = sc.nextInt();
                draw[j] = sc.nextInt();
                lose[j] = sc.nextInt();
                if (win[j] + draw[j] + lose[j] != 5) {
                    isPossible = false;
                }
            }
            if (isPossible) {
                isPossible = checkCombination(0, 1);
            }
            System.out.printf("%d ", isPossible ? 1 : 0);
        }

        sc.close();
    }

    static boolean checkCombination(int team1, int team2) {
        if (team1 == 5) {
            return true;
        }

        if (team2 == 6) {
            return checkCombination(team1 + 1, team1 + 2);
        }

        if (win[team1] > 0 && lose[team2] > 0) {
            win[team1]--;
            lose[team2]--;
            if (checkCombination(team1, team2 + 1)) return true;
            win[team1]++;
            lose[team2]++;
        }

        if (win[team2] > 0 && lose[team1] > 0) {
            win[team2]--;
            lose[team1]--;
            if (checkCombination(team1, team2 + 1)) return true;
            win[team2]++;
            lose[team1]++;
        }

        if (draw[team1] > 0 && draw[team2] > 0) {
            draw[team1]--;
            draw[team2]--;
            if (checkCombination(team1, team2 + 1)) return true;
            draw[team1]++;
            draw[team2]++;
        }

        return false;
    }
}
