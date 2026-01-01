#pragma once

#include <filesystem>

	inline void wordToLower(std::string& string) {		//оставляет только буквы + приводит их к нижнему регистру
		std::wstring ws = std::filesystem::path(string).native();	//решено было написать свою функцию, т.к. готовые решения
		std::wstring outWs;											//не работают с кириллицей

		for (wchar_t wc : ws) {

			unsigned int c = (unsigned int)wc;
			switch (wc) {
			case L'A': outWs += 'a'; break;
			case L'B': outWs += 'b'; break;
			case L'C': outWs += 'c'; break;
			case L'D': outWs += 'd'; break;
			case L'E': outWs += 'e'; break;
			case L'F': outWs += 'f'; break;
			case L'G': outWs += 'g'; break;
			case L'H': outWs += 'h'; break;
			case L'I': outWs += 'i'; break;
			case L'J': outWs += 'j'; break;
			case L'K': outWs += 'k'; break;
			case L'L': outWs += 'l'; break;
			case L'M': outWs += 'm'; break;
			case L'N': outWs += 'n'; break;
			case L'O': outWs += 'o'; break;
			case L'P': outWs += 'p'; break;
			case L'Q': outWs += 'q'; break;
			case L'R': outWs += 'r'; break;
			case L'S': outWs += 's'; break;
			case L'T': outWs += 't'; break;
			case L'U': outWs += 'u'; break;
			case L'V': outWs += 'v'; break;
			case L'W': outWs += 'w'; break;
			case L'X': outWs += 'x'; break;
			case L'Y': outWs += 'y'; break;
			case L'Z': outWs += 'z'; break;

			case L'a': outWs += 'a'; break;
			case L'b': outWs += 'b'; break;
			case L'c': outWs += 'c'; break;
			case L'd': outWs += 'd'; break;
			case L'e': outWs += 'e'; break;
			case L'f': outWs += 'f'; break;
			case L'g': outWs += 'g'; break;
			case L'h': outWs += 'h'; break;
			case L'i': outWs += 'i'; break;
			case L'j': outWs += 'j'; break;
			case L'k': outWs += 'k'; break;
			case L'l': outWs += 'l'; break;
			case L'm': outWs += 'm'; break;
			case L'n': outWs += 'n'; break;
			case L'o': outWs += 'o'; break;
			case L'p': outWs += 'p'; break;
			case L'q': outWs += 'q'; break;
			case L'r': outWs += 'r'; break;
			case L's': outWs += 's'; break;
			case L't': outWs += 't'; break;
			case L'u': outWs += 'u'; break;
			case L'v': outWs += 'v'; break;
			case L'w': outWs += 'w'; break;
			case L'x': outWs += 'x'; break;
			case L'y': outWs += 'y'; break;
			case L'z': outWs += 'z'; break;

			case L'А': outWs += L'а'; break;
			case L'Б': outWs += L'б'; break;
			case L'В': outWs += L'в'; break;
			case L'Г': outWs += L'г'; break;
			case L'Д': outWs += L'д'; break;
			case L'Е': outWs += L'е'; break;
			case L'Ё': outWs += L'ё'; break;
			case L'Ж': outWs += L'ж'; break;
			case L'З': outWs += L'з'; break;
			case L'И': outWs += L'и'; break;
			case L'Й': outWs += L'й'; break;
			case L'К': outWs += L'к'; break;
			case L'Л': outWs += L'л'; break;
			case L'Н': outWs += L'н'; break;
			case L'М': outWs += L'м'; break;
			case L'О': outWs += L'о'; break;
			case L'П': outWs += L'п'; break;
			case L'Р': outWs += L'р'; break;
			case L'С': outWs += L'с'; break;
			case L'Т': outWs += L'т'; break;
			case L'У': outWs += L'у'; break;
			case L'Ф': outWs += L'ф'; break;
			case L'Х': outWs += L'х'; break;
			case L'Ц': outWs += L'ц'; break;
			case L'Ч': outWs += L'ч'; break;
			case L'Ш': outWs += L'ш'; break;
			case L'Щ': outWs += L'щ'; break;
			case L'Ь': outWs += L'ь'; break;
			case L'Ъ': outWs += L'ъ'; break;
			case L'Ы': outWs += L'ы'; break;
			case L'Э': outWs += L'э'; break;
			case L'Ю': outWs += L'ю'; break;
			case L'Я': outWs += L'я'; break;

			case L'а': outWs += L'а'; break;
			case L'б': outWs += L'б'; break;
			case L'в': outWs += L'в'; break;
			case L'г': outWs += L'г'; break;
			case L'д': outWs += L'д'; break;
			case L'е': outWs += L'е'; break;
			case L'ё': outWs += L'ё'; break;
			case L'ж': outWs += L'ж'; break;
			case L'з': outWs += L'з'; break;
			case L'и': outWs += L'и'; break;
			case L'й': outWs += L'й'; break;
			case L'к': outWs += L'к'; break;
			case L'л': outWs += L'л'; break;
			case L'н': outWs += L'н'; break;
			case L'м': outWs += L'м'; break;
			case L'о': outWs += L'о'; break;
			case L'п': outWs += L'п'; break;
			case L'р': outWs += L'р'; break;
			case L'с': outWs += L'с'; break;
			case L'т': outWs += L'т'; break;
			case L'у': outWs += L'у'; break;
			case L'ф': outWs += L'ф'; break;
			case L'х': outWs += L'х'; break;
			case L'ц': outWs += L'ц'; break;
			case L'ч': outWs += L'ч'; break;
			case L'ш': outWs += L'ш'; break;
			case L'щ': outWs += L'щ'; break;
			case L'ь': outWs += L'ь'; break;
			case L'ъ': outWs += L'ъ'; break;
			case L'ы': outWs += L'ы'; break;
			case L'э': outWs += L'э'; break;
			case L'ю': outWs += L'ю'; break;
			case L'я': outWs += L'я'; break;
			default: break;
			}
		}
		string = std::filesystem::path(outWs).string();
	};