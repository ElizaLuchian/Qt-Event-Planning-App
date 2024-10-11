//
// Created by 40745 on 29/04/2024.
//

#include <fstream>
#include "HtmlUserFile.h"

void HtmlUserFile::writeToFile() {
    FileUserRepo::writeToFile();
    ofstream filename(fileName + ".html");
    vector<Event> eventList=getEventList();
    filename << "<!DOCTYPE html>    <!-- write this exactly as it is here -->\n"
                "<html> <!-- write this exactly as it is here -->\n"
                "<head> <!--  write this exactly as it is here -->\n"
                "    <title>Playlist</title> <!-- replace “Playlist” with the title for your HTML -->\n"
                "</head> <!-- write this exactly as it is here (close head tag) -->\n"
                "<body> <!-- write this exactly as it is here -->\n"
                "<table border=\"1\"> <!-- write this exactly as it is here -->\n"
                "    <tr> <!-- tr = table row; 1 row for each entity -->\n"
                "        <td>Event title</td> <!-- td = table data; 1 td for each attribute of the entity -->\n"
                "        <td>Description</td>\n"
                "        <td>NumberOfPeople</td>\n"

                "      <td>Date</td>\n"
                "        <td>Event link!!</td>\n"
                "    </tr>";

    for (auto &el : eventList)
    {
        filename << " <tr>"
                    "<td>"+el.getTitle()+"</td>"
                                         "<td>"+ el.getDescription() + "</td>"
                                                                       " <td>" + to_string(el.getNumberOfPeople()) +"</td>"
                                                                                                                    " <td>" + to_string(el.getDay()) + "." + to_string(el.getMonth())+ "." + to_string(el.getYear())+ "...." + to_string(el.getHours())+ ":" + to_string(el.getMinutes())+ "</td>"

                                                                                                                                                                                                                                                                                           "<td><a href=\""+el.getLink()+"\">Link</a></td>"

                                                                                                                                                                                                                                                                                                                         "</tr>";
    }
    filename << "\n"
                "</table>\n"
                "</body>\n"
                "</html>";
}

std::string HtmlUserFile::generateCommand() {
    return "start http://localhost:63342/oop_a6_7_ElizaLuchian/cmake-build-debug-coverage/" + fileName + ".html";
}
