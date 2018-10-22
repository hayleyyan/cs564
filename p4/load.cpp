#include <stdio.h>
#include "sqlite3.h"
#include <fstream>
#include <cstring>
#include <iostream> 

using namespace std;

int main(int argc, char* argv[])
{
  sqlite3 *db;
  int conn;
  const char* sql;
  conn = sqlite3_open("nutrients.db", &db); //sqlite3 api

  //reading the text file
  ifstream foodDes;
  ifstream foodGroup;
  ifstream langual;
  ifstream langDes;
  ifstream nutData;
  ifstream nutrDef;
  ifstream srcCode;
  ifstream derivCode;
  ifstream weight;
  ifstream footnote;
  ifstream dataLink;
  ifstream dataSrc;
  

  foodDes.open("FOOD_DES.txt");
  foodGroup.open("FD_GROUP.txt");
  langual.open("LANGUAL.txt");
  langDes.open("LANGDESC.txt");
  nutData.open("NUT_DATA.txt");
  nutrDef.open("NUTR_DEF.txt");
  srcCode.open("SRC_CD.txt");
  derivCode.open("DERIV_CD.txt");
  weight.open("WEIGHT.txt");
  footnote.open("FOOTNOTE.txt");
  dataLink.open("DATSRCLN.txt");
  dataSrc.open("DATA_SRC.txt");



  conn = sqlite3_open("nutrient.db", &db); //sqlite3 api

  if( conn ){
    fprintf(stderr, "Unable to open the database: %s\n", sqlite3_errmsg(db)); //sqlite3 api
    
    return(0);
  }else{

    

    //Food description file
    sql = "CREATE TABLE FOOD_DES("
          "NDB_No       int,"
          "FdGrp_Cd     int,"
          "Long_Desc    varchar(200),"
          "Shrt_Desc    char(60));"
          "PRIMARY KEY(NDB_No) )";

    //Food group
         "CREATE TABLE FD_GROUP("
          "FdGrp_Cd      int,"
          "FdGrp_Desc,   varchar(60),"
          "PRIMARY KEY (FdGrp_Cd) );";

    //Langual factor file
          "CREATE TABLE LANGUAL("
          "NDB_No       int,"
          "Factor_Code  text,"
          "PRIMARY KEY(NDB_No) );";

    //langual factor description file
          "CREATE TABLE LANGDESC("
          "Factor_Code  text,"
          "Description  varchar(140),"
          "PRIMARY KEY(Factor_Code) );";

    //Nurtient Data file
          "CREATE TABLE NUT_DATA("
          "NDB_No       int,"
          "Nutr_No      int,"
          "Nutr_Val     float,"
          "Num_Data_Pts float,"
          "Src_Cd       int,"
          "Deriv_Cd     int,"
          "PRIMARY KEY (NDB_No, Nutr_No) );";

    //Nutrient definition file 
          "CREATE TABLE NUTR_DEF("
          "Nutr_No      int,"
          "Units        char(7),"
          "Tagname      varchar(20),"
          "NurtrDesc    varchar(60),"
          "Num_Dec      float,"
          "PRIMARY KEY(Nutr_No) );";

    //Source code file
          "CREATE TABLE SRC_CD("
          "Src_Cd       int,"
          "SrcCd_Desc   varchar(60),"
          "PRIMARY KEY(Src_Cd) );";

    //Data Derivation Code Description file
          "CREATE TABLE DERIV_CD("
          "Deriv_Cd     varchar(4),"
          "Deriv_Desc   varchar(120),"
          "PRIMARY KEY(Deriv_Cd) );";

    //Weight file
          "CREATE TABLE WEIGHT("
          "NDB_No       int,"
          "Seq          int,"
          "Amount       float,"
          "Msre_Desc    varchar(84),"
          "Gm_Wgt       float,"
          "Num_Data_Pts float,"
          "Std_Dev      float,"
          "PRIMARY KEY(NDB_No) );";

    //footnote file
          "CREATE TABLE FOOTNOTE("
          "NDB_No       int,"
          "Footnt_No    int,"
          "Footnt_Type  char(1),"
          "Nutr_No      int,"
          "Footnt_Txt   text);";

    //Source of data link file
          "CREATE TABLE DATSRCLN("
          "NDB_No       int,"
          "Nutr_No      int,"
          "DataSrc_ID   char(6),"
          "PRIMARY KEY(NDB_No) );";

    //Sources of data file
          "CREATE TABLE DATA_SRC("
          "DataSrc_ID   char(6),"
          "Authors      varchar(255),"
          "Title        varchar(255),"
          "Year         char(4),"
          "Journal      varchar(135),"
          "Vol_City     varchar(16),"
          "Issue_State  varchar(5),"
          "Start_Page   char(5),"
          "End_Page     char(5),"
          "PRIMARY KEY(DataSrc_ID) );";

    conn = sqlite3_exec(db, sql, NULL, NULL, NULL);
    fprintf(stderr, "database opened successfully\n");
  }
  sqlite3_close(db); //sqlite3 api
}

