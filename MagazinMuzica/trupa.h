#pragma once
#include "artist.h"
#include<string>
#include<ostream>
class Trupa :public Artist {
private:
	int m_numar_membrii;
public:
	Trupa(const std::string& nume, const std::string& tara, int  membrii);
	int GetNumarMembrii() const;
	void SetNumarMembrii(int numar_membrii);
	std::ostream& print(std::ostream& os) const override;
};
