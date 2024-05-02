#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* child[5];
};

class Book {
    Node* root;
    int numChapters, numSections, numSubsections;

public:
    Book() {
        root = new Node();
        root->name = "Book";
        for (int i = 0; i < 5; i++) {
            root->child[i] = NULL;
        }
        numChapters = numSections = numSubsections = 0;
    }

    void addChapter(string chapterName) {
        Node* chapter = new Node();
        chapter->name = chapterName;
        chapter->child[0] = NULL;
        int i = 1;
        Node* temp = root;
        while (temp->child[i - 1] != NULL) {
            temp = temp->child[i - 1];
            i++;
        }
        temp->child[i - 1] = chapter;
        numChapters++;
    }

    void addSection(string chapterName, string sectionName) {
        Node* chapter = root;
        for (int i = 0; i < numChapters; i++) {
            if (chapter->child[i]->name == chapterName) {
                chapter = chapter->child[i];
                break;
            }
        }

        Node* section = new Node();
        section->name = sectionName;
        section->child[0] = NULL;
        int i = 1;
        Node* temp = chapter;
        while (temp->child[i - 1] != NULL) {
            temp = temp->child[i - 1];
            i++;
        }
        temp->child[i - 1] = section;
        numSections++;
    }

    void addSubsection(string chapterName, string sectionName, string subsectionName) {
        Node* chapter = root;
        for (int i = 0; i < numChapters; i++) {
            if (chapter->child[i]->name == chapterName) {
                chapter = chapter->child[i];
                break;
            }
        }

        Node* section = chapter->child[0];
        for (int i = 0; i < numSections; i++) {
            if (section->child[i]->name == sectionName) {
                section = section->child[i];
                break;
            }
        }

        Node* subsection = new Node();
        subsection->name = subsectionName;
        subsection->child[0] = NULL;
        int i = 1;
        Node* temp = section;
        while (temp->child[i - 1] != NULL) {
            temp = temp->child[i - 1];
            i++;
        }
        temp->child[i - 1] = subsection;
        numSubsections++;
    }

    void printNodes() {
        printNodesHelper(root, 0);
    }

    void printNodesHelper(Node* node, int level) {
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }
        cout << node->name << endl;
        for (int i = 0; i < 5; i++) {
            if (node->child[i] != NULL) {
                printNodesHelper(node->child[i], level + 1);
            }
        }
    }
};

int main() {
    Book book;
    book.addChapter("Chapter 1");
    book.addChapter("Chapter 2");
    book.addSection("Chapter 1", "Section 1.1");
    book.addSection("Chapter 1", "Section 1.2");
    book.addSection("Chapter 2", "Section 2.1");
    book.addSubsection("Chapter 1", "Section 1.1", "Subsection 1.1.1");
    book.addSubsection("Chapter 1", "Section 1.2", "Subsection 1.2.1");
    book.addSubsection("Chapter 2", "Section 2.1", "Subsection 2.1.1");
    book.printNodes();
    return 0;
}