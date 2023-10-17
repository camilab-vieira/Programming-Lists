package ListaJava.Q2;

public abstract class Investiment {
    private double incomeRate;
    private String code;
    private double investedMoney;

    public Investiment(){
        this.incomeRate = 3.0;
        this.code = "default";
        this.investedMoney = 100.0;
    }
    
    public Investiment(double incomeRate, String code){
        this.incomeRate = incomeRate;
        this.code = code;
        this.investedMoney = 100.0;
    }
    
    public Investiment(double incomeRate, String code, double investedMoney){
        this.incomeRate = incomeRate;
        this.code = code;
        this.investedMoney = investedMoney;
    }

    public void setIncomeRate(double incomeRate){
        this.incomeRate = incomeRate;
    }

    public double getIncomeRate(){
        return this.incomeRate;
    }

    public void setCode(String code){
        this.code = code;
    }

    public String getCode(){
        return this.code;
    }

    public void setInvestedMoney(double investedMoney){
        this.investedMoney = investedMoney;
    }

    public double getInvestedMoney(){
        return this.investedMoney;
    }

    public void invest(double amount){
        this.investedMoney += amount;
    }

    public abstract double yield();

    public abstract double yield(int time);
}
