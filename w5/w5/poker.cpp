#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <algorithm>

using namespace std;

enum class suit :short {SPADE, HEART, DIAMOND, CLUB};
ostream& operator<<(ostream& out, suit& s)
{
	if (s == suit::SPADE)
	{
		out << "SPADE";
	}
	if (s == suit::HEART)
	{
		out << "HEART";
	}
	if (s == suit::DIAMOND)
	{
		out << "DIAMOND";
	}
	if (s == suit::CLUB)
	{
		out << "CLUB";
	}
	return out;
}

class pips 
{
public:
	pips(int v):v(v) {}
	friend ostream& operator<<(ostream& out, pips& p);
	int getValue() { return v; }
private:
	int v;
};

ostream& operator<<(ostream& out, pips& p)
{
	out << p.getValue();
	return out;
}

class card
{
public:
	card(suit s = suit::SPADE, pips v = 1) :s(s), v(v) {}
	friend ostream& operator<<(ostream& out, card& c);
	suit getSuit() { return s; }
	pips getPips() { return v; }
private:
	suit s;
	pips v;
};

ostream& operator<<(ostream& out, card& c)
{
	out << c.v << " " << c.s;
	return out;
}

void initDeck(vector<card> &deck)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < 14; ++j)
		{
			card c(static_cast<suit>(i), j);
			deck[(i * 13) + (j - 1)] = c;
		}
	}
}

void print(vector<card>& deck)
{
	for (auto c: deck)
	{
		cout << c;
	}
	cout << endl;
}

bool isFlush(vector<card>& hand)
{
	suit s = hand[0].getSuit();
	for(auto p = hand.begin() + 1; p != hand.end(); ++p)
	{
		if (p->getSuit() != s)
		{
			return false;
		}
	}
	return true;
}

bool isStraight(vector<card>& hand)
{
	bool isStraight = true;
	int pipsVal[5];
	for (int i = 0; i < 5; ++i)
	{
		pipsVal[i] = (hand[i].getPips()).getValue();
	}

	for (int i = 1; i < 5; ++i)
	{
		if (pipsVal[i] != pipsVal[i-1]+1)
		{
			isStraight = false;
		}
	}
	//ace special case
	if (pipsVal[0] == 1 && isStraight == false)
	{
		isStraight = (pipsVal[1] == 10)&& (pipsVal[2] == 11) 
			&& (pipsVal[3] == 12) && (pipsVal[4] == 13);
	}
	return isStraight;
}

bool isStraightFlush(vector<card>& hand)
{
	return isStraight(hand) && isFlush(hand);
}

int main()
{
	vector<card> deck(52);
	srand(time(0));
	initDeck(deck);
	int straights = 0;
	int flushes = 0;
	int straightFlushes = 0;
	for (int trial = 0; trial < 1000000; ++trial)
	{
		random_shuffle(deck.begin(), deck.end());
		vector<card> hand(5);
		
		int i = 0;
		for (auto p = deck.begin(); i < 5; ++p)
		{
			hand[i++] = *p;
		}

		if (isFlush(hand))
		{
			flushes++;
		}
		if (isStraight(hand))
		{
			straights++;
		}
		if (isStraightFlush(hand))
		{
			straightFlushes++;
		}
	}

	cout << "Flush Probability: " << (flushes/1000000.0) << endl;
	cout << "Straight Probability: " << (straights / 1000000.0) << endl;
	cout << "Straight Flush Probability: " << (straightFlushes / 1000000.0) << endl;
	cout << "Enter any key to exit: ";
	int x;
	cin >> x;
	return 0;
}