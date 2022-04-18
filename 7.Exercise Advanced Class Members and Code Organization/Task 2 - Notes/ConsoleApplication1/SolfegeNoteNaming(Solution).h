#pragma once
#ifndef SolfegeNoteNaming_H
#define SolfegeNoteNaming_H

class SolfegeNoteNaming {
public:
	NoteName operator()(const std::string& NoteText) const {
		if (NoteText == "Do") {
			return NoteName('C');
		}
		else if (NoteText == "Re") {
			return NoteName('D');
		}
		else if (NoteText == "Mi") {
			return NoteName('E');
		}
		else if (NoteText == "Fa") {
			return NoteName('F');
		}
		else if (NoteText == "Sol") {
			return NoteName('G');
		}
		else if (NoteText == "La") {
			return NoteName('A');
		}
		else if (NoteText == "Si") {
			return NoteName('B');
		}
		else {
			return NoteName('?');
		}
	}
};

#endif // !SolfegeNoteNaming_H
