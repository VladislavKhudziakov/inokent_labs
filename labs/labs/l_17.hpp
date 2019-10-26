//
// Created by movleaxedx on 27.10.19.
//

#pragma once
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

#define MALE true
#define  FEMALE false

namespace l_17
{
  struct student
  {
    typedef bool sex_t;

    size_t group_code;
    size_t number;
    std::string name;
    std::string surname;
    std::time_t birth_date;
    sex_t sex;
  };

  std::ostream& operator<< (std::ostream& os, const student& student) {
    std::string code = std::to_string(student.group_code);
    std::string number = std::to_string(student.number);
    auto birth_date = std::put_time(std::localtime(&student.birth_date), "%F");
    std::string sex("m");

    if (!student.sex) {
      sex = "f";
    }

    std::string out;
    std::ostringstream oss;
    oss << "CODE: " << code << "\n" << "NUMBER: " << number << "\n"
        << "NAME: " << student.name << "\n" << "SURNAME: " << student.surname << "\n"
        << "BITH_DATE: " << birth_date << "\n" << "SEX: " << sex << "\n";

    os << oss.str() << std::endl;

    return os;
  }

}

