#include "Cards.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Cards::Cards()
{
	//render the instace of card by default
	render = true;

}

Cards::Cards(string categorie)
{
	this->categorie = categorie;
	render = true;
}

Cards::~Cards()
{
}

vector< pair<string, Cards*> > Cards::categorize(vector<pair<string, string>>* titles, vector<pair<string, string>>* bodyText, vector<string>* categories, vector<vector<string>>* cardCat)
{
	vector<string>::iterator catIt = categories->begin();

	vector< pair<string, Cards*> > categorizedCards;
	categorizedCards.reserve(8);

	// insert all categorie names
	while (catIt != categories->end())
	{
		categorizedCards.push_back( make_pair(*catIt, new Cards(*catIt) ) ); // set the instance var categorie 
		catIt++;
	}
	return *sort(&categorizedCards, cardCat, titles, bodyText); // dereference to create a copy to main
}


vector<pair<string, Cards*>>* Cards::sort(vector< pair<string, Cards*> >* categorizedCards, vector<vector<string>>* cardCat, vector<pair<string, string>>* titles, vector<pair<string, string>>* bodyText)
{

	for (int i = 0; i < categorizedCards->size(); i++)
	{
		for (int j = 0; j < cardCat->size(); j++)
		{
			string searched = categorizedCards->at(i).first;
			if (findCat(cardCat->at(j).begin(), cardCat->at(j).end(), searched)) { // help function to search vector for string
				float x1 = rand() % 400;
				float y1 = rand() % 400;
				categorizedCards->at(i).second->addCard(new Card(x1, y1, titles->at(j).first, bodyText->at(j).first));
			}

		}
	}

	return categorizedCards; // return pointer to avoid making an extra copy locally in Cards
}

void Cards::renderCards()
{
	// only render if true
	if (render) {
		for (int i = 0; i < allcards.size(); i++)
		{
			allcards[i]->renderCard();
		}
	}

}

void Cards::addCard(Card *card)
{
	allcards.push_back(card);
}

bool Cards::findCat(vector<string>::iterator first, vector<string>::iterator last, string searched)
{
	for (; first != last; ++first)
	{
		if (*first == searched) return true;
	}
	return false;
}

void Cards::collision()
{
}

void Cards::setPath(Card &inst)
{
}

void Cards::search()
{
}

void Cards::mouseDown(MouseEvent event)
{
	if (render)
	{
		for (int i = 0; i < allcards.size(); i++)
		{
			allcards[i]->mouseDown(event);
		}
	}

}

void Cards::mouseDrag(MouseEvent event)
{
	if (render)
	{
		for (int i = 0; i < allcards.size(); i++)
		{
			allcards[i]->mouseDrag(event);
		}
	}

}

void Cards::mouseUp(MouseEvent event)
{
	if (render)
	{
		for (int i = 0; i < allcards.size(); i++)
		{
			allcards[i]->mouseUp(event);
		}
	}

}