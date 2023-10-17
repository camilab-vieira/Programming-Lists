package ListaJava.Q2;

public class MainClass {
    public static void main(String args[]){
        Investiment investimentType1 = new RealEstateFund();
        Investiment investimentType2 = new RealEstateFund(2.0, "type2");
        Investiment investimentType3 = new RealEstateFund(1.0, "type3", 1000.0);
    
        double type1Result, type2Result, type3Result;

        investimentType1.invest(400.0);
        type1Result = investimentType1.getInvestedMoney();
        System.out.println(type1Result);
        //inicio - 100,0; 100 + 400 => 500,0

        type2Result = investimentType2.yield();
        System.out.printf("%.2f\n", type2Result);
        //inicio - 100,0; taxa - 2%; 100 * 0,02 => 2,0 de rendimento

        type3Result = investimentType3.yield(2);
        System.out.printf("%.2f\n",type3Result);
        //inicio - 1000,0; taxa - 1%; 1000*(1,01)^2 - 1000 => 20,1 de rendimento
    }
}
