class Account{
	private:
		string id;
		string name;
		int balance=0;
	public:
		Account(string id,string name);
		Account(string id,string name,int balance);
		string getID();
		string getName();
		int getBalance();
		int credit(int amount);
		int debit(int amount);
		int transferTo(Account account,int amount);
		string toString();