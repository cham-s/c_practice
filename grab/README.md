##grab

Finds the word in a file and display all the lines where the word appears. It also display the line number

TODO: 
- Make it case incensitive
- Get data from stdin in case of redirection

Known Bugs:
- The line number comes back to 1, when the buffer gets refilled with data.
- At buffer max even though there is no newline. The last character is considered as a newline. 

Source for source.txt: www.Time.com, Oct 12 2015.
```bash
>$ ./grab "gun" source.txt
2: Hillary Clinton talks gun control at town hall meeting
>$

>$ ./grab "help" source.txt
5: “The diversity of Nevada and the outreach programs you use there can help us reach out to those communities in other states,” he said.
>$

>$ ./grab "public" source.txt
24: “We gave — and we know we have — the best candidate for president of all the candidates for president, Democrat or Republican — Hillary Clinton,” Castro told about two dozen Clinton volunteers who, armed with clipboards filled with computer-generated lists of potential voters, were about to set out for an afternoon of door-knocking in heavily Latino East Las Vegas.
28: Yet neither was 2008, when Clinton won the Nevada caucus. Her state director then was Robby Mook, who is now her national campaign manager. Her field director that year was Marlon Marshall, now the national campaign’s director of public engagement. Emmy Ruiz, who worked on the Clinton 2008 effort and then ran Obama’s successful 2012 race in Nevada, is now overseeing Clinton’s 2016 effort in the state.
>$
```
