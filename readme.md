# Voting Management System

A simple implementation of a voting systme in c which has provisions for admin voter and candidate interface
## Overview

This system simulates a simple election process using:
- **Linked lists** for in-memory voter and candidate storage  
- **Text files** for persistent data (`VOTER.txt`, `CANDIDATE.txt`)  
- **Admin module** for election control  
- **Voter module** for casting and modifying votes
- **candidate module** for candidate registering (NOTA is also available as candidate option)  

## Features
### admin features
- login authentication
- start eletion
- end election
- add voter
- adds voters to VOTER.txt and candidates to CANDIDATE.txt
- at end of election updates VOTER.txt to show castedvote
### voter features
- login check based on voter list provided by admin
- cast vote
- update vote
- delete current vote
### candidate feature
- login authentication based on voter list
- register as candidate (only when voter already in voter list NOTA is a candidate also)

## Project Structure
VotingSystem/
├── VOTER.txt
├── CANDIDATE.txt 
├── main.c 
├── README.md 
└── src/
└── VOTER1.txt
## File Formats

### **VOTER.txt**

### **VOTER1.txt**

### **CANDIDATE.txt**
## Key Functions

| Function | Purpose |
|---------|----------|
| `adm_login()` | Admin authentication |
| `write_voter()` | Add voter to file |
| `voter_linked_list()` | Build voter Linked List |
| `add_candidate()` | Add candidate entry |
| `casting_vote()` | Voter casts vote |
| `update_vote()` | Modify voter’s vote |
| `votes()` | Display results (sorted) |
| `update_voter()` | Save updated voter list |

## Compilation & Execution

### Compile:
gcc main.c -o voting
## future enhancements

- Encrypted admin & voter login
