//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include<queue>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

class Question{
	public:
	char* Text;
	char* answer1;
	char* answer2;
	char* answer3;
	char* answer4;
	int correctAnswer;
	int quesMarks;

	Question( ){
	}


	Question(char* text, char* ans1, char* ans2, char* ans3, char* ans4, int correctAns,int Marks){
			 Text = text;
			 answer1 = ans1;
			 answer2 = ans2;
			 answer3 = ans3;
			 answer4 =  ans4;
			 correctAnswer = correctAns;
			  quesMarks =   Marks;
	}
};


std::queue<Question> LoadQuestion(){
	  Question q1 = Question("Humayun was born in the year ___________.","1508","1608","1708","1808",1,1 );
	  Question q2 = Question("Who Invented the 3-D printer?","Nick Holonyak","Elias Howe","Chuck Hull","Christiaan Huygens",3,2);
	  Question q3 = Question("What is the maximum number of Members in Lok Sabha?","512","542","552","532",3,1);
	  Question q4 = Question("Who was court poet of Samudragupta?","Chand Bardai","Bhavabhuti","Banabhatta","Harishen",4,1);
	  Question q5 = Question("Which Veda depicts the information about the most ancient Vedic age culture?","Atharvaveda","Samaveda","Rig Veda","Yajurveda",3,5);

	  std::queue<Question> questions;
	  questions.push(q1);
	  questions.push(q2);
	  questions.push(q3);
	  questions.push(q4);
	  questions.push(q5);


	  return questions;
};

 std::queue<Question> questions;
 Question currentQuestion;

 int points =0;
 int selectedAnswer=0;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
   questions = LoadQuestion();
   currentQuestion =   questions.front();

	QuestionLabel->Text =  currentQuestion.Text;
	Answer1RadioButton->Text =   currentQuestion.answer1;
	Answer2RadioButton->Text =   currentQuestion.answer2;
	Answer3RadioButton->Text =   currentQuestion.answer3;
	Answer4RadioButton->Text =   currentQuestion.answer4;

	questions.pop();

	PointsLabel->Text = points;
	ConfirmButton->Text = "Confirm " ;
	PointsLabel->Visible = false;

}
//--------------------------------------------------------------------------
void __fastcall TForm1::Answer1RadioButtonChange(TObject *Sender)
{
	  selectedAnswer = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Answer2RadioButtonChange(TObject *Sender)
{
		 selectedAnswer = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Answer3RadioButtonChange(TObject *Sender)
{
		selectedAnswer = 3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Answer4RadioButtonChange(TObject *Sender)
{
		  selectedAnswer = 4;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmButtonClick(TObject *Sender)
{

	if( selectedAnswer) {
	 if( selectedAnswer ==  currentQuestion.correctAnswer){

		  points+=currentQuestion.quesMarks;
		  PointsLabel->Text =   points;

	 }

	 if(!questions.empty()){

		currentQuestion =   questions.front();

		QuestionLabel->Text =  currentQuestion.Text;
		Answer1RadioButton->Text =   currentQuestion.answer1;
		Answer2RadioButton->Text =   currentQuestion.answer2;
		Answer3RadioButton->Text =   currentQuestion.answer3;
		Answer4RadioButton->Text =   currentQuestion.answer4;

		questions.pop();

		Answer1RadioButton->IsChecked = false;
		Answer2RadioButton->IsChecked = false;
		Answer3RadioButton->IsChecked = false;
		Answer4RadioButton->IsChecked = false;
	 }
	 else{
			ConfirmButton->Enabled = false;
			ConfirmButton->Text = "Test Finished";
			PointsLabel->Visible = true;
	 }
	}
   selectedAnswer =0;
}
//---------------------------------------------------------------------------
