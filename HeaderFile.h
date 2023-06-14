#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <string>

class SimSports {
public:
    virtual void engage() = 0;
    virtual void pickSport() = 0;
    virtual void guide() = 0;
    virtual ~SimSports() {}
};

class AthleticAcademy : public SimSports {
protected:
    std::string academyName;
    int enrolledSims;

public:
    AthleticAcademy() : enrolledSims(0) {}

    std::string getAcademyName() const { return academyName; }
    void setAcademyName(const std::string& name) { academyName = name; }

    int getEnrolledSims() const { return enrolledSims; }
    void setEnrolledSims(int numSims) { enrolledSims = numSims; }

    void engage() override = 0;
};

class SportActivities : public SimSports {
protected:
    std::string sportName;

public:
    virtual void pickSport() = 0;

    std::string getSportName() const { return sportName; }
};


class Trainer : public SimSports {
protected:
    std::string trainerName;
    int experienceLevel;

public:
    void guide() override;

    std::string getTrainerName() const { return trainerName; }
    void setTrainerName(const std::string& name) { trainerName = name; }

    int getExperienceLevel() const { return experienceLevel; }
    void setExperienceLevel(int level) { experienceLevel = level; }
};

class EnrollInSport : public AthleticAcademy {
public:
    void engage() override;
};

class ParticipateInTraining : public AthleticAcademy {
public:
    void engage() override;
};

class OlympicCompetition : public AthleticAcademy {
public:
    void engage() override;
};

class Swimming : public SportActivities {
public:
    Swimming() {
        sportName = "Swimming";
    }

    void pickSport() override;
};

class Gymnastics : public SportActivities {
public:
    Gymnastics() {
        sportName = "Gymnastics";
    }

    void pickSport() override;
};

class Skiing : public SportActivities {
public:
    Skiing() {
        sportName = "Skiing";
    }

    void pickSport() override;
};

class IceSkating : public SportActivities {
public:
    IceSkating() {
        sportName = "Ice Skating";
    }

    void pickSport() override;
};

class TrainAthletes : public Trainer {
public:
    void guide() override;
};

class PerformStrategy : public Trainer {
public:
    void guide() override;
};

#endif // HEADERFILE_H
