import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Random;

/**
 * @Title InfixGenerator.java
 * @Package
 * @Description TODO
 * @author yikliu
 * @date Apr 24, 2012 7:42:09 PM
 * @version V1.0
 */

/**
 * @ClassName InfixGenerator
 * @Package
 * @Description TODO
 * @author yikliu
 * @date Apr 24, 2012 7:42:09 PM
 * 
 */

public class InfixGenerator{
	public StringBuilder	infix;
	public Random			rand	= new Random();

	public int				upper	= 5;

	public enum token {
		open_paren, close_paren, operator, operand
	};

	public void generatePlainInfixExpression(int operandLimit, int operatorCount, int pare_level) {
		infix = new StringBuilder();
		int i = 0;
		while (i < operatorCount) {
			infix.append(generateOperand(operandLimit));
			infix.append(" ");
			infix.append(generateOperator());
			infix.append(" ");
			i++;
		}
		infix.append(generateOperand(operandLimit));
	}

	public boolean generateRandomBoolean() {
		int num = rand.nextInt();
		return num % 2 == 0;
	}

	public void generateComplexInfixExpression(int length, int pare_level) {
		infix = new StringBuilder();
		int i = 0;
		int level = 0;

		int open_paren = 1;
		int num = 2;
		int op = 4;
		int close_paren = 8;

		int lasttoken = 0;
		int accept_token = open_paren | num;

		boolean can_make_close_paren_now = false;
		boolean reaching_pare_level = false;

		while (i < length) {
			int k = rand.nextInt();
			switch (k % 4) {
				case 0: //open paren
					if (level < pare_level && (accept_token & open_paren) != 0 && !reaching_pare_level) {
						infix.append(" ");
						infix.append(generateOpenParen());
						level++;
						accept_token = open_paren | num;
						can_make_close_paren_now = false;					
						if(level == pare_level)
							reaching_pare_level = true;
						
						lasttoken = 1;
					}
					break;
				case 1: //operator
					if ((accept_token & op) != 0) {
						infix.append(" ");
						infix.append(generateOperator());
						accept_token = open_paren | num;
						can_make_close_paren_now = true;
						lasttoken = 4;
						i++;
					}
					break;
				case 2: // num
					if ((accept_token & num) != 0) {
						infix.append(" ");
						infix.append(generateOperand(upper));
						accept_token = op | close_paren;
						lasttoken = 2;
					}
					break;
				case 3: //close paren
					if ((accept_token & close_paren) != 0 && level > 0 && can_make_close_paren_now && reaching_pare_level) {
						infix.append(" ");
						infix.append(generateCloseParen());
						level--;
						
						if(level == 0){
							reaching_pare_level = false;
						}
						
						accept_token = op | close_paren;
						lasttoken = 8;
					}
					break;
			}
			
		}

		switch (lasttoken) {
			case 1:
				infix.append(" ");
				infix.append(generateOperand(upper));
				infix.append(" ");
				infix.append(generateOperator());
				infix.append(" ");
				infix.append(generateOperand(upper));
				can_make_close_paren_now = true;
				break;
			case 2:
				if (!can_make_close_paren_now) {
					infix.append(" ");
					infix.append(generateOperator());
					infix.append(" ");
					infix.append(generateOperand(upper));
				}
				break;
			case 4:
				infix.append(" ");
				infix.append(generateOperand(upper));
				break;
			case 8:
				break;
		}

		for (int j = 0; j < level; j++) {
			infix.append(" ");
			infix.append(generateCloseParen());
		}

	}

	public int generateOperand(int upper) {
		int operand = 0;
		while (operand == 0) {
			operand = rand.nextInt(upper);
		}
		return operand;
	}

	public String generateOperator() {
		int op = rand.nextInt(100) % 3; //% 3 to avoid / and %
		switch (op) {
			case 0:
				return "+";
			case 1:
				return "-";
			case 2:
				return "*";
			case 3:
				return "/";
			case 4:
				return "%";
			default:
				break;
		}
		return null;
	}

	public String generateOpenParen() {
		return "(";
	}

	public String generateCloseParen() {
		return ")";
	}

	public String getString() {
		return infix.toString();
	}

	/**
	 * @Title: main
	 * @Description: TODO
	 * @param @param args
	 * @return void
	 * @throws
	 */
	public static void main(String[] args) {
		InfixGenerator gen = new InfixGenerator();
		
		try {
			
			
			for (int lenghth = 1000; lenghth <= 100000; lenghth +=1000){
				for (int level = 100; level <=1000; level += 100){
					// Create file					
					FileWriter fstream = new FileWriter(
							"d:/Dropbox/Code/CPP/CSCI507/Assignment5_VS/Assignment5/files/input_"+lenghth+"_"+level+".txt");
					BufferedWriter out = new BufferedWriter(fstream);
					out.write(String.format("%d",lenghth));
					out.newLine();
					out.write(String.format("%d",level));
					out.newLine();
					gen.generateComplexInfixExpression(lenghth, level);
					out.write(gen.getString());				
					out.close();
				}
			}	
		
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}

}
