Voting Management System - README

This file explains each structure, function, and the flow of the program.  
Length kept under 100 lines as requested.

------------------------------------------------------------

1. DATA STRUCTURES
------------------

1.1 Voter Structure
- name: voter name
- voterId: voter’s ID
- casted_vote: party voted
- next: pointer for linked list

1.2 Candidate Structure
- name: candidate’s name
- voterId: ID of voter who registered as candidate
- party_name: party contesting
- no_of_votes: vote count
- next: pointer for linked list

------------------------------------------------------------

2. ADMIN FUNCTIONS
------------------

adm_login()
- Confirms admin username & password.

admin_logic()
- Lets admin add voters.
- Option to terminate election.
- Returns:
  1 → start election
  3 → terminate election

------------------------------------------------------------

3. VOTER FILE FUNCTIONS
-----------------------

write_voter(name, id)
- Appends voter data into VOTER.txt.

read_voter()
- Prints voter list from file.

update_voter(head)
- Writes complete voter linked list to VOTER.txt.

voter_linked_list(head)
- Reads VOTER.txt and builds linked list.

------------------------------------------------------------

4. CANDIDATE FUNCTIONS
----------------------

new_candidate()
- Creates a candidate node.

add_candidate()
- Appends candidate to linked list.

write_candidate()
- Writes candidate details to CANDIDATE.txt.

Candidate_enrollment()
- Allows a voter to register as a candidate.

------------------------------------------------------------

5. VOTING FUNCTIONS
-------------------

casting_vote(voter, cand_list)
- Voter chooses party.
- Updates voter->casted_vote and candidate vote count.

update_vote(voter, cand_list)
- Removes old vote, casts new one.

delete_vote(voter, cand_list)
- Removes vote and sets casted_vote to NOTA.

------------------------------------------------------------

6. SUPPORT FUNCTIONS
--------------------

check(head, name, voterId)
- Checks if voter exists in linked list.

votes(cand_head)
- Sorts candidates by votes and prints results.

------------------------------------------------------------

7. MAIN PROGRAM FLOW
---------------------

- Creates NOTA candidate.
- Displays menu:
  1. Admin
  2. Voter
  3. Candidate Enrollment
  4. Exit

Admin Mode:
- Add voters.
- End election and show results.

Voter Mode:
- Login with name + ID.
- Cast / update / delete vote.

Candidate Enrollment:
- Voter registers as a candidate.

Exit:
- Program terminates.

------------------------------------------------------------
END OF README

