#ifndef WORDS
#define WORDS

#include <array>
#include <string_view>

inline const std::array<std::string_view, 100>* getDict()
{
	static constexpr std::array<std::string_view, 100> words = {
		"abstract", "accurate", "advocate", "ambitious", "analyze",
		"apparent", "approach", "attitude", "benefit", "calculate",
		"capable", "censure", "clarify", "coherent", "commence",
		"component", "conclude", "conduct", "confirm", "consequence",
		"consider", "constitute", "context", "contribute", "convene",
		"corporate", "credible", "criteria", "crucial", "deduce",
		"define", "demonstrate", "derive", "designate", "diverse",
		"document", "dominant", "economy", "effective", "eligible",
		"emerge", "emphasize", "establish", "evaluate", "evidence",
		"exclude", "exhibit", "expand", "exploit", "facilitate",
		"federal", "flexible", "generate", "guarantee", "identify",
		"illustrate", "impact", "implement", "imply", "indicate",
		"individual", "innovate", "integral", "interpret", "investigate",
		"involve", "justify", "liberal", "maintain", "mediate",
		"modify", "monitor", "objective", "obtain", "occasion",
		"occupy", "oppose", "outcome", "paradigm", "perceive",
		"precede", "predict", "primary", "process", "professional",
		"project", "pursue", "relevant", "resolve", "resource",
		"respond", "restrict", "structure", "subsequent", "substitute",
		"sufficient", "suggest", "technique", "theory", "transmit"
	};

	return &words;
}



#endif
