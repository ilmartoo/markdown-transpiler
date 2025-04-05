#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

// Tokens //////////
enum Tokens
{
    HASHTAG = 0,         // #
    EQUALS,              // =
    MINUS,               // -
    NEWLINE,             // \n
    ASTERISK,            // *
    UNDERSCORE,          // _
    NUMBER_ONE,          // 1
    NUMBER_ELSE,         // [02-9]
    DOT,                 // .
    PLUS,                // +
    BACKSLASH,           // \ 
    BACKTICK,            // `
    BRACKET_OPEN,        // [
    BRACKET_CLOSE,       // ]
    CURLY_BRACKET_OPEN,  // {
    CURLY_BRACKET_CLOSE, // }
    ANGLE_BRACKET_OPEN,  // <
    ANGLE_BRACKET_CLOSE, // >
    PARENTHESES_OPEN,    // (
    PARENTHESES_CLOSE,   // )
    EXCLAMATION_MARK,    // !
    PIPE,                // |
    COLON,               // :
    INDENTATION,         // (\t) | ( {4})
    CROSS,               // [Xx]
};

enum Nodes
{
    HEADER_1 = -1,
    HEADER_2 = -2,
    HEADER_3 = -3,
    HEADER_4 = -4,
    HEADER_5 = -5,
    HEADER_6 = -6,
    BOLD,
    ITALIC,
    BLOCKQUOTE,
    ORDERED_LIST,
    UNORDERED_LIST,
    TASK_LIST,
    LIST_ITEM,
    ESCAPED_CHARACTER,
    LINK,
    IMAGE,
    CODE,
    CODE_BLOCK,
    HORIZONTAL_RULE,
    REFERENCE_LINK_POSITION,
    REFERENCE_LINK_DATA,
    TABLE, // TODO
    FOOTNOTE_POSITION,
    FOOTNOTE_DATA,
    STRIKETHROUGH,
    SUBSCRIPT,
    SUPERSCRIPT,
};

enum Groups
{
};

#define NODE_DEFINITION(name, id, group, content)

#define LEXEME_SIZE

#endif // CONSTANTS_H