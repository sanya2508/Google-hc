import java.util.Scanner;

public class Bus{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		
		for(int i = 0; i < testCases; i++) {
			int n = scan.nextInt();
			long d = scan.nextLong();
			long dayStart = d;
			long array[] = new long[n];
			
			for(int j = 0; j < n; j++) {
				array[j] = scan.nextLong();
			}
			
			int index = n - 1;
			while(true) {
				if(index == -1)
					break;
				
				long days = dayStart % array[index]; 
				if(days == 0)
					index--;
				else
					dayStart -= days;
			}
			
			System.out.print("Case #" + (i +1) + ": " + dayStart+ "\n");
		}
	}
}
