/**
	* \file IexBrlyIni.h
	* data blocks and readers/writers for import/export complex IexBrlyIni (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Jan 2021
	*/
// IP header --- ABOVE

#ifndef IEXBRLYINI_H
#define IEXBRLYINI_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsBrly.h"
#include "VecBrlyVIop.h"

#define VecVIexBrlyIniIme IexBrlyIni::VecVIme

#define ImeitemIBrlyIniAVControlPar IexBrlyIni::ImeitemIAVControlPar
#define ImeIBrlyIniAVControlPar IexBrlyIni::ImeIAVControlPar
#define VecWImeIBrlyIniAVControlParIel IexBrlyIni::ImeIAVControlPar::VecWIel

#define ImeitemIBrlyIniJAVKeylistKey IexBrlyIni::ImeitemIJAVKeylistKey
#define ImeIBrlyIniJAVKeylistKey IexBrlyIni::ImeIJAVKeylistKey
#define VecWImeIBrlyIniJAVKeylistKeyIel IexBrlyIni::ImeIJAVKeylistKey::VecWIel

#define ImeitemIBrlyIniAVKeylistKey IexBrlyIni::ImeitemIAVKeylistKey
#define ImeIBrlyIniAVKeylistKey IexBrlyIni::ImeIAVKeylistKey
#define VecWImeIBrlyIniAVKeylistKeyIel IexBrlyIni::ImeIAVKeylistKey::VecWIel

#define ImeitemIBrlyIniAVValuelistVal IexBrlyIni::ImeitemIAVValuelistVal
#define ImeIBrlyIniAVValuelistVal IexBrlyIni::ImeIAVValuelistVal
#define VecWImeIBrlyIniAVValuelistValIel IexBrlyIni::ImeIAVValuelistVal::VecWIel

#define ImeitemIBrlyIniMFile IexBrlyIni::ImeitemIMFile
#define ImeIBrlyIniMFile IexBrlyIni::ImeIMFile
#define VecWImeIBrlyIniMFileIel IexBrlyIni::ImeIMFile::VecWIel

#define ImeitemIBrlyIniMLocation IexBrlyIni::ImeitemIMLocation
#define ImeIBrlyIniMLocation IexBrlyIni::ImeIMLocation
#define VecWImeIBrlyIniMLocationIel IexBrlyIni::ImeIMLocation::VecWIel

#define ImeitemIBrlyIniMOperator IexBrlyIni::ImeitemIMOperator
#define ImeIBrlyIniMOperator IexBrlyIni::ImeIMOperator
#define VecWImeIBrlyIniMOperatorIel IexBrlyIni::ImeIMOperator::VecWIel

#define ImeitemIBrlyIniMPlntype IexBrlyIni::ImeitemIMPlntype
#define ImeIBrlyIniMPlntype IexBrlyIni::ImeIMPlntype
#define VecWImeIBrlyIniMPlntypeIel IexBrlyIni::ImeIMPlntype::VecWIel

#define ImeitemIBrlyIniAMRegionDstswitch IexBrlyIni::ImeitemIAMRegionDstswitch
#define ImeIBrlyIniAMRegionDstswitch IexBrlyIni::ImeIAMRegionDstswitch
#define VecWImeIBrlyIniAMRegionDstswitchIel IexBrlyIni::ImeIAMRegionDstswitch::VecWIel

#define ImeitemIBrlyIniJMRegion IexBrlyIni::ImeitemIJMRegion
#define ImeIBrlyIniJMRegion IexBrlyIni::ImeIJMRegion
#define VecWImeIBrlyIniJMRegionIel IexBrlyIni::ImeIJMRegion::VecWIel

#define ImeitemIBrlyIniJMRegionTitle IexBrlyIni::ImeitemIJMRegionTitle
#define ImeIBrlyIniJMRegionTitle IexBrlyIni::ImeIJMRegionTitle
#define VecWImeIBrlyIniJMRegionTitleIel IexBrlyIni::ImeIJMRegionTitle::VecWIel

#define ImeitemIBrlyIniMRegion IexBrlyIni::ImeitemIMRegion
#define ImeIBrlyIniMRegion IexBrlyIni::ImeIMRegion
#define VecWImeIBrlyIniMRegionIel IexBrlyIni::ImeIMRegion::VecWIel

#define ImeitemIBrlyIniAMUsergroupAccess IexBrlyIni::ImeitemIAMUsergroupAccess
#define ImeIBrlyIniAMUsergroupAccess IexBrlyIni::ImeIAMUsergroupAccess
#define VecWImeIBrlyIniAMUsergroupAccessIel IexBrlyIni::ImeIAMUsergroupAccess::VecWIel

#define ImeitemIBrlyIniAMUserAccess IexBrlyIni::ImeitemIAMUserAccess
#define ImeIBrlyIniAMUserAccess IexBrlyIni::ImeIAMUserAccess
#define VecWImeIBrlyIniAMUserAccessIel IexBrlyIni::ImeIAMUserAccess::VecWIel

#define ImeitemIBrlyIniJMUserState IexBrlyIni::ImeitemIJMUserState
#define ImeIBrlyIniJMUserState IexBrlyIni::ImeIJMUserState
#define VecWImeIBrlyIniJMUserStateIel IexBrlyIni::ImeIJMUserState::VecWIel

#define ImeitemIBrlyIniJMPersonLastname IexBrlyIni::ImeitemIJMPersonLastname
#define ImeIBrlyIniJMPersonLastname IexBrlyIni::ImeIJMPersonLastname
#define VecWImeIBrlyIniJMPersonLastnameIel IexBrlyIni::ImeIJMPersonLastname::VecWIel

#define ImeitemIBrlyIniMPerson IexBrlyIni::ImeitemIMPerson
#define ImeIBrlyIniMPerson IexBrlyIni::ImeIMPerson
#define VecWImeIBrlyIniMPersonIel IexBrlyIni::ImeIMPerson::VecWIel

#define ImeitemIBrlyIniMUser IexBrlyIni::ImeitemIMUser
#define ImeIBrlyIniMUser IexBrlyIni::ImeIMUser
#define VecWImeIBrlyIniMUserIel IexBrlyIni::ImeIMUser::VecWIel

#define ImeitemIBrlyIniMUsergroup IexBrlyIni::ImeitemIMUsergroup
#define ImeIBrlyIniMUsergroup IexBrlyIni::ImeIMUsergroup
#define VecWImeIBrlyIniMUsergroupIel IexBrlyIni::ImeIMUsergroup::VecWIel

/**
	* IexBrlyIni
	*/
namespace IexBrlyIni {
	/**
		* VecVIme (full: VecVIexBrlyIniIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMREGIONDSTSWITCH = 1;
		static const Sbecore::uint IMEIAMUSERACCESS = 2;
		static const Sbecore::uint IMEIAMUSERGROUPACCESS = 3;
		static const Sbecore::uint IMEIAVCONTROLPAR = 4;
		static const Sbecore::uint IMEIAVKEYLISTKEY = 5;
		static const Sbecore::uint IMEIAVVALUELISTVAL = 6;
		static const Sbecore::uint IMEIJAVKEYLISTKEY = 7;
		static const Sbecore::uint IMEIJMPERSONLASTNAME = 8;
		static const Sbecore::uint IMEIJMREGION = 9;
		static const Sbecore::uint IMEIJMREGIONTITLE = 10;
		static const Sbecore::uint IMEIJMUSERSTATE = 11;
		static const Sbecore::uint IMEIMFILE = 12;
		static const Sbecore::uint IMEIMLOCATION = 13;
		static const Sbecore::uint IMEIMOPERATOR = 14;
		static const Sbecore::uint IMEIMPERSON = 15;
		static const Sbecore::uint IMEIMPLNTYPE = 16;
		static const Sbecore::uint IMEIMREGION = 17;
		static const Sbecore::uint IMEIMUSER = 18;
		static const Sbecore::uint IMEIMUSERGROUP = 19;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAVControlPar (full: ImeitemIBrlyIniAVControlPar)
		*/
	class ImeitemIAVControlPar : public BrlyAVControlPar {

	public:
		ImeitemIAVControlPar(const Sbecore::uint ixBrlyVControl = 0, const std::string& Par = "", const std::string& Val = "");
		ImeitemIAVControlPar(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxBrlyVControl;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVControlPar (full: ImeIBrlyIniAVControlPar)
		*/
	class ImeIAVControlPar {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAVControlParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXBRLYVCONTROL = 1;
			static const Sbecore::uint PAR = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVControlPar();
		~ImeIAVControlPar();

	public:
		std::vector<ImeitemIAVControlPar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey (full: ImeitemIBrlyIniJAVKeylistKey)
		*/
	class ImeitemIJAVKeylistKey : public BrlyJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey(const Sbecore::uint x1IxBrlyVLocale = 0, const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJAVKeylistKey(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxBrlyVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey (full: ImeIBrlyIniJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXBRLYVLOCALE = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAVKeylistKey();
		~ImeIJAVKeylistKey();

	public:
		std::vector<ImeitemIJAVKeylistKey*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey (full: ImeitemIBrlyIniAVKeylistKey)
		*/
	class ImeitemIAVKeylistKey : public BrlyAVKeylistKey {

	public:
		ImeitemIAVKeylistKey(const Sbecore::uint klsIxBrlyVKeylist = 0, const std::string& sref = "", const std::string& Avail = "", const std::string& Implied = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIAVKeylistKey(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefKlsIxBrlyVKeylist;

		ImeIJAVKeylistKey imeijavkeylistkey;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey (full: ImeIBrlyIniAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFKLSIXBRLYVKEYLIST = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint AVAIL = 4;
			static const Sbecore::uint IMPLIED = 8;
			static const Sbecore::uint TITLE = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVKeylistKey();
		~ImeIAVKeylistKey();

	public:
		std::vector<ImeitemIAVKeylistKey*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVValuelistVal (full: ImeitemIBrlyIniAVValuelistVal)
		*/
	class ImeitemIAVValuelistVal : public BrlyAVValuelistVal {

	public:
		ImeitemIAVValuelistVal(const Sbecore::uint vlsIxBrlyVValuelist = 0, const Sbecore::uint x1IxBrlyVLocale = 0, const std::string& Val = "");
		ImeitemIAVValuelistVal(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefVlsIxBrlyVValuelist;
		std::string srefX1IxBrlyVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVValuelistVal (full: ImeIBrlyIniAVValuelistVal)
		*/
	class ImeIAVValuelistVal {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAVValuelistValIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFVLSIXBRLYVVALUELIST = 1;
			static const Sbecore::uint SREFX1IXBRLYVLOCALE = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVValuelistVal();
		~ImeIAVValuelistVal();

	public:
		std::vector<ImeitemIAVValuelistVal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile (full: ImeitemIBrlyIniMFile)
		*/
	class ImeitemIMFile : public BrlyMFile {

	public:
		ImeitemIMFile(const std::string& osrefKContent = "", const std::string& Filename = "", const std::string& srefKMimetype = "", const std::string& Comment = "");
		ImeitemIMFile(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile (full: ImeIBrlyIniMFile)
		*/
	class ImeIMFile {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMFileIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint OSREFKCONTENT = 1;
			static const Sbecore::uint FILENAME = 2;
			static const Sbecore::uint SREFKMIMETYPE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFile();
		~ImeIMFile();

	public:
		std::vector<ImeitemIMFile*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMLocation (full: ImeitemIBrlyIniMLocation)
		*/
	class ImeitemIMLocation : public BrlyMLocation {

	public:
		ImeitemIMLocation(const Sbecore::uint ixVBasetype = 0, const std::string& hsrefRefBrlyMRegion = "", const std::string& sref = "", const std::string& srefICAO = "", const std::string& Title = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0, const std::string& tz = "");
		ImeitemIMLocation(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string hsrefRefBrlyMRegion;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMLocation (full: ImeIBrlyIniMLocation)
		*/
	class ImeIMLocation {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMLocationIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint HSREFREFBRLYMREGION = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint SREFICAO = 8;
			static const Sbecore::uint TITLE = 16;
			static const Sbecore::uint ALT = 32;
			static const Sbecore::uint THETA = 64;
			static const Sbecore::uint PHI = 128;
			static const Sbecore::uint TZ = 256;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMLocation();
		~ImeIMLocation();

	public:
		std::vector<ImeitemIMLocation*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMOperator (full: ImeitemIBrlyIniMOperator)
		*/
	class ImeitemIMOperator : public BrlyMOperator {

	public:
		ImeitemIMOperator(const std::string& sref = "", const std::string& srefICAO = "", const std::string& Title = "");
		ImeitemIMOperator(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMOperator (full: ImeIBrlyIniMOperator)
		*/
	class ImeIMOperator {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMOperatorIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFICAO = 2;
			static const Sbecore::uint TITLE = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMOperator();
		~ImeIMOperator();

	public:
		std::vector<ImeitemIMOperator*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPlntype (full: ImeitemIBrlyIniMPlntype)
		*/
	class ImeitemIMPlntype : public BrlyMPlntype {

	public:
		ImeitemIMPlntype(const std::string& sref = "", const std::string& Title = "", const std::string& srefBrlyKEqptype = "", const Sbecore::usmallint Capacity = 0);
		ImeitemIMPlntype(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPlntype (full: ImeIBrlyIniMPlntype)
		*/
	class ImeIMPlntype {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMPlntypeIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint SREFBRLYKEQPTYPE = 4;
			static const Sbecore::uint CAPACITY = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPlntype();
		~ImeIMPlntype();

	public:
		std::vector<ImeitemIMPlntype*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMRegionDstswitch (full: ImeitemIBrlyIniAMRegionDstswitch)
		*/
	class ImeitemIAMRegionDstswitch : public BrlyAMRegionDstswitch {

	public:
		ImeitemIAMRegionDstswitch(const Sbecore::uint startd = 0, const Sbecore::uint startt = 0);
		ImeitemIAMRegionDstswitch(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string ftmStartd;
		std::string ftmStartt;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMRegionDstswitch (full: ImeIBrlyIniAMRegionDstswitch)
		*/
	class ImeIAMRegionDstswitch {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAMRegionDstswitchIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint FTMSTARTD = 1;
			static const Sbecore::uint FTMSTARTT = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMRegionDstswitch();
		~ImeIAMRegionDstswitch();

	public:
		std::vector<ImeitemIAMRegionDstswitch*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMRegion (full: ImeitemIBrlyIniJMRegion)
		*/
	class ImeitemIJMRegion : public BrlyJMRegion {

	public:
		ImeitemIJMRegion(const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::uint ixVDst = 0, const double toffset = 0.0);
		ImeitemIJMRegion(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string ftmX1Startd;
		std::string ftmX1Stopd;
		std::string srefIxVDst;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMRegion (full: ImeIBrlyIniJMRegion)
		*/
	class ImeIJMRegion {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJMRegionIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint FTMX1STARTD = 1;
			static const Sbecore::uint FTMX1STOPD = 2;
			static const Sbecore::uint SREFIXVDST = 4;
			static const Sbecore::uint TOFFSET = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMRegion();
		~ImeIJMRegion();

	public:
		std::vector<ImeitemIJMRegion*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMRegionTitle (full: ImeitemIBrlyIniJMRegionTitle)
		*/
	class ImeitemIJMRegionTitle : public BrlyJMRegionTitle {

	public:
		ImeitemIJMRegionTitle(const Sbecore::uint x1IxBrlyVLocale = 0, const std::string& Title = "");
		ImeitemIJMRegionTitle(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxBrlyVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMRegionTitle (full: ImeIBrlyIniJMRegionTitle)
		*/
	class ImeIJMRegionTitle {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJMRegionTitleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXBRLYVLOCALE = 1;
			static const Sbecore::uint TITLE = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMRegionTitle();
		~ImeIJMRegionTitle();

	public:
		std::vector<ImeitemIJMRegionTitle*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMRegion (full: ImeitemIBrlyIniMRegion)
		*/
	class ImeitemIMRegion : public BrlyMRegion {

	public:
		ImeitemIMRegion(const std::string& hsrefSupRefBrlyMRegion = "", const std::string& sref = "", const std::string& Title = "", const Sbecore::uint ixVDst = 0, const double toffset = 0.0);
		ImeitemIMRegion(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefSupRefBrlyMRegion;
		std::string srefIxVDst;

		ImeIAMRegionDstswitch imeiamregiondstswitch;
		ImeIJMRegion imeijmregion;
		ImeIJMRegionTitle imeijmregiontitle;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRegion (full: ImeIBrlyIniMRegion)
		*/
	class ImeIMRegion {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMRegionIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HSREFSUPREFBRLYMREGION = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint TITLE = 4;
			static const Sbecore::uint SREFIXVDST = 8;
			static const Sbecore::uint TOFFSET = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMRegion();
		~ImeIMRegion();

	public:
		std::vector<ImeitemIMRegion*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUsergroupAccess (full: ImeitemIBrlyIniAMUsergroupAccess)
		*/
	class ImeitemIAMUsergroupAccess : public BrlyAMUsergroupAccess {

	public:
		ImeitemIAMUsergroupAccess(const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0);
		ImeitemIAMUsergroupAccess(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxBrlyVFeatgroup;
		std::string srefsIxBrlyWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUsergroupAccess (full: ImeIBrlyIniAMUsergroupAccess)
		*/
	class ImeIAMUsergroupAccess {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAMUsergroupAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXBRLYVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXBRLYWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUsergroupAccess();
		~ImeIAMUsergroupAccess();

	public:
		std::vector<ImeitemIAMUsergroupAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUserAccess (full: ImeitemIBrlyIniAMUserAccess)
		*/
	class ImeitemIAMUserAccess : public BrlyAMUserAccess {

	public:
		ImeitemIAMUserAccess(const Sbecore::uint x1IxBrlyVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixBrlyWAccess = 0);
		ImeitemIAMUserAccess(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxBrlyVFeatgroup;
		std::string srefsIxBrlyWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUserAccess (full: ImeIBrlyIniAMUserAccess)
		*/
	class ImeIAMUserAccess {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAMUserAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXBRLYVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXBRLYWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUserAccess();
		~ImeIAMUserAccess();

	public:
		std::vector<ImeitemIAMUserAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMUserState (full: ImeitemIBrlyIniJMUserState)
		*/
	class ImeitemIJMUserState : public BrlyJMUserState {

	public:
		ImeitemIJMUserState(const Sbecore::uint ixVState = 0);
		ImeitemIJMUserState(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMUserState (full: ImeIBrlyIniJMUserState)
		*/
	class ImeIJMUserState {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJMUserStateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSTATE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMUserState();
		~ImeIJMUserState();

	public:
		std::vector<ImeitemIJMUserState*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPersonLastname (full: ImeitemIBrlyIniJMPersonLastname)
		*/
	class ImeitemIJMPersonLastname : public BrlyJMPersonLastname {

	public:
		ImeitemIJMPersonLastname(const std::string& Lastname = "");
		ImeitemIJMPersonLastname(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPersonLastname (full: ImeIBrlyIniJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJMPersonLastnameIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint LASTNAME = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMPersonLastname();
		~ImeIJMPersonLastname();

	public:
		std::vector<ImeitemIJMPersonLastname*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIBrlyIniMPerson)
		*/
	class ImeitemIMPerson : public BrlyMPerson {

	public:
		ImeitemIMPerson(const Sbecore::uint ixVSex = 0, const std::string& Title = "", const std::string& Firstname = "", const std::string& Lastname = "");
		ImeitemIMPerson(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVSex;

		ImeIJMPersonLastname imeijmpersonlastname;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIBrlyIniMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMPersonIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSEX = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint FIRSTNAME = 4;
			static const Sbecore::uint LASTNAME = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPerson();
		~ImeIMPerson();

	public:
		std::vector<ImeitemIMPerson*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUser (full: ImeitemIBrlyIniMUser)
		*/
	class ImeitemIMUser : public BrlyMUser {

	public:
		ImeitemIMUser(const std::string& sref = "", const Sbecore::uint ixVState = 0, const Sbecore::uint ixBrlyVLocale = 0, const Sbecore::uint ixBrlyVUserlevel = 0, const std::string& Password = "", const std::string& Fullkey = "", const std::string& Comment = "");
		ImeitemIMUser(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;
		std::string srefIxBrlyVLocale;
		std::string srefIxBrlyVUserlevel;

		ImeIAMUserAccess imeiamuseraccess;
		ImeIJMUserState imeijmuserstate;
		ImeIMPerson imeimperson;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUser (full: ImeIBrlyIniMUser)
		*/
	class ImeIMUser {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMUserIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXVSTATE = 2;
			static const Sbecore::uint SREFIXBRLYVLOCALE = 4;
			static const Sbecore::uint SREFIXBRLYVUSERLEVEL = 8;
			static const Sbecore::uint PASSWORD = 16;
			static const Sbecore::uint FULLKEY = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUser();
		~ImeIMUser();

	public:
		std::vector<ImeitemIMUser*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUsergroup (full: ImeitemIBrlyIniMUsergroup)
		*/
	class ImeitemIMUsergroup : public BrlyMUsergroup {

	public:
		ImeitemIMUsergroup(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMUsergroup(DbsBrly* dbsbrly, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMUsergroupAccess imeiamusergroupaccess;
		ImeIMUser imeimuser;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUsergroup (full: ImeIBrlyIniMUsergroup)
		*/
	class ImeIMUsergroup {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMUsergroupIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint COMMENT = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUsergroup();
		~ImeIMUsergroup();

	public:
		std::vector<ImeitemIMUsergroup*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMLocation& imeimlocation, ImeIMOperator& imeimoperator, ImeIMPlntype& imeimplntype, ImeIMRegion& imeimregion, ImeIMUsergroup& imeimusergroup);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMLocation& imeimlocation, ImeIMOperator& imeimoperator, ImeIMPlntype& imeimplntype, ImeIMRegion& imeimregion, ImeIMUsergroup& imeimusergroup);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMLocation& imeimlocation, ImeIMOperator& imeimoperator, ImeIMPlntype& imeimplntype, ImeIMRegion& imeimregion, ImeIMUsergroup& imeimusergroup);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMLocation& imeimlocation, ImeIMOperator& imeimoperator, ImeIMPlntype& imeimplntype, ImeIMRegion& imeimregion, ImeIMUsergroup& imeimusergroup);

	void writeTxt(std::fstream& outfile, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMLocation& imeimlocation, ImeIMOperator& imeimoperator, ImeIMPlntype& imeimplntype, ImeIMRegion& imeimregion, ImeIMUsergroup& imeimusergroup);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMLocation& imeimlocation, ImeIMOperator& imeimoperator, ImeIMPlntype& imeimplntype, ImeIMRegion& imeimregion, ImeIMUsergroup& imeimusergroup);

	std::map<Sbecore::uint,Sbecore::uint> icsBrlyVIopInsAll();
	Sbecore::uint getIxBrlyVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsBrlyVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixBrlyVIop);
};

#endif
