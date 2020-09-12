# Introduction to System Design

### What are Functional Requirements?

A functional requirement defines a system or its component. It describes the functions a software must perform. A function is nothing but inputs, its behavior and outputs. It can be a calculation, data manipulation, business process, user interaction or any specific functionality which defines what function a system is likely to perform. 

It's a broad definition and so I usually take this approach when trying to list down functional requirement, if any requirements that you can place in any one of the following groups mentioned below, then that requirement is a part of functional requirement. 

1. Business requirements - This usually contains the ultimate goal, such as an order system, an online catalogue or a physical product. It can also include things like approval workflows and authorization levels. 

2. Administrative functions - These are the routine things the system will do, such as reporting. 

3. User requirements - These are what the user of the system can do, such as place an order or browse the online catalogue. 

4. System requirements - These are things like software and hardware specifications, system responses or system actions. 

### What are Non-functional Requirements?

A non-functional requirement defines the quality attribute of a software system. They represent a set of standards used to judge the specific operation of a system. For example, how fast does the website load?

A non-functional requirement is essential to ensure the usability and effectiveness of the entire software system. Failing to meet non-functional requirements can result in systems that fail to satisfy user needs.

Personally, for me it's more hard to capture non-functional requirements than functional requirements but for this process as well, I can similar approach, if any requirements that you can place in any one of the following groups mentioned below, then that requirement is a part of non-functional requirement. 

1. Usability - This focuses on the appearance of the user interface and how people interact with it. Example:-  What color are the screens? How bug are the buttons?

2. Reliability / Availability - Waht are the uptime requirements? Does it need to function 24/7/365?

3. Scalability - As needs grow, can the system handle it? For physical installations, this includes spare hardware or space to install it in the future. 

4. Performance - How fast does it need to operate?

5. Supportability - Is support provided in-house or is remote accessibility for external resources required?

6. Security - What are the security requirements, both for the physical installation and from a cyber perspective?


### What are some examples of functional and non-functional requirements?

Although there are gray areas in classifying a requirement as either functional or non-functional, here are some examples:

#### Functional

- When the user enters the information, the system shall send an approval request.
- The server shall log all changes to existing data.
- When 24 hours have passed since the last database backup, the server shall automatically back up the database.
- The local terminal shall automatically print a list of orders every 4 hours.
- When the local time is 0800, the server shall email a report of open issues to all managers.
- The system shall only allow managers to view customer banking data.


#### Non-functional

- Database security shall meet HIPAA requirements.
- The layout shall allow users to reach their profile data from any page within 3 clicks.
- If a user has not changed their password for 56 days, then the system shall require a password change upon login.
- The system must accommodate a minimum of 3 million concurrent users.
- All web pages shall load within 4 seconds.
- The server room shall accommodate a future doubling of installed hardware.
- The server room shall be accessible by authorized employees 24 hours per day.
- The background colour for all screens shall be #fff4b6.
- System programming shall not use deprecated code.


### What are best practices for functional and non-functional requirements?

Regardless of the form they take, the key to effective functional and non-functional requirements is that they are clear and as easy to understand as possible. Each audience is different, but in all cases the closer the requirements are to being in natural language, the better. And when it comes to language, the use of active voice is preferred over passive voice. Active voice usually results in clearer and shorter requirements by ensuring there is an “actor” in each requirement statement.

When writing requirements, make sure they are complete and accurate and avoid vagueness. At the same time, avoid including extraneous information that may confuse people. Use “must” instead of “should” as you write the requirements document. Be consistent in the use of terminology and units, and be consistent in the format and language used.

As you seek to make the requirements clear, translate stakeholder and user input into discrete requirements. If they say the system must be “fast”, what does that mean? When they say the web site must be able to handle “a lot” of users, what does that mean? Turn these types of requirements into a number and quantify them.

Make sure that requirements fully cover every scenario, which means including requirements detailing what the system shall not do, but be careful not to over-specify. Focus on the features that the users truly need. More is not always better and often leads to increased cost, diluted impact, and a bloated product that confuses users and is difficult to use. You should be able to trace back every requirement to one of the project objectives. It can be useful to benchmark against other companies in the same industry to understand what they are doing. Sometimes this means you aim for “just as good” as the competition, and sometimes it gives you a point from which to be better.

It is important when talking with users and stakeholders to try to understand the bigger picture of where their requirements are coming from and how they relate to the project objective. What are they really trying to do? Sometimes they will present a solution when they really should present a problem so the best solution can be brainstormed by a larger team. Also, be sure to understand their authority to make functional requirement requests. Usually, a project manager has the final say and should be consulted before adding additional requirements. As you gather requirements, document assumptions in a requirements traceability matrix so you can later go back to the person who requested the feature with any questions you may have. Specification development is frequently an iterative process. As the requirements are developed, be sure they are feasible and non-conflicting.

Defining requirements can be confusing. Although it is not always possible, try to make them understandable by non-technical stakeholders, and use visuals as much as possible to reinforce the information.

As a final takeaway, never consider non-functional requirements to be unimportant, despite the name. A website that takes 30 seconds to load might meet its functional requirements but is still not usable.