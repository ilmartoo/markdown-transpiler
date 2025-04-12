#pragma once
#ifndef TOKENS_H
#define TOKENS_H

typedef enum Tokens
{
    // Punctuation
    NEWLINE,         // \n
    TABULAR,         // \s{4}|\t
    HORIZONTAL_RULE, // \n\n-{3,}$

    // Headers
    HEADER_1,        // ^#
    HEADER_2,        // ^##
    HEADER_3,        // ^###
    HEADER_4,        // ^####
    HEADER_5,        // ^#####
    HEADER_6,        // ^######
    HEADER_1_LINE,   // ^\s*(\w\s*)+\n={3,}$
    HEADER_2_LINE,   // ^\s*(\w\s*)+\n-{3,}$
    HEADER_ID_START, // (HEADER_1|HEADER_2|HEADER_3|HEADER_4|HEADER_5|HEADER_6)\s*{#
    HEADER_ID_END,   // }

    // Styling
    BOLD_ASTERISK,     // **
    BOLD_UNDERSCORE,   // __
    ITALIC_ASTERISK,   // *
    ITALIC_UNDERSCORE, // _
    STRIKETHROUGH,     // ~~
    SUBSCRIPT,         // ~
    SUPERSCRIPT,       // ^

    // Quotes
    BLOCKQUOTE_LINE,      // >
    BLOCKQUOTE_MULTILINE, // >>>

    // Lists
    ORDERED_LIST_ITEM_FIRST, // 1.
    ORDERED_LIST_ITEM_OTHER, // \d.
    UNORDERED_LIST_ITEM,     // -
    TASK_LIST_ITEM_TODO,     // - [ ]
    TASK_LIST_ITEM_DONE,     // - [x]

    // Escaped characters
    ESCAPED_BACKSLASH,           // \\ 
    ESCAPED_BACKTICK,            // \`
    ESCAPED_ASTERISK,            // \*
    ESCAPED_UNDERSCORE,          // \_
    ESCAPED_CURLY_BRACKET_OPEN,  // \{
    ESCAPED_CURLY_BRACKET_CLOSE, // \}
    ESCAPED_BRACKET_OPEN,        // \[
    ESCAPED_BRACKET_CLOSE,       // \]
    ESCAPED_ANGLE_BRACKET_OPEN,  // \<
    ESCAPED_ANGLE_BRACKET_CLOSE, // \>
    ESCAPED_HASHTAG,             // \#
    ESCAPED_PLUS,                // \+
    ESCAPED_MINUS,               // \-
    ESCAPED_DOT,                 // \.
    ESCAPED_EXCLAMATION_MARK,    // \!
    ESCAPED_PIPE,                // \|

    // Code
    CODE_INLINE_SINGLE,  // `
    CODE_INLINE_DOUBLE,  // ``
    CODE_BLOCK_BACKTICK, // ```
    CODE_BLOCK_WIGGLE,   // ~~~

    // Table
    TABLE_CELL_LIMIT,           // |
    TABLE_HEADER_LIMIT_DEFAULT, // -{3,}
    TABLE_HEADER_LIMIT_LEFT,    // :-{3,}
    TABLE_HEADER_LIMIT_CENTER,  // :-{3,}:
    TABLE_HEADER_LIMIT_RIGHT,   // -{3,}:

    // Link, Image, Footnote
    OPEN_BRACKET, // [
    // LINK_TEXT_START
    // REFERENCE_LINK_HOLE_TEXT_START
    // REFERENCE_LINK_HOLE_ID_START
    CLOSE_BRACKET, // ]
    // LINK_TEXT_END
    // IMAGE_TEXT_END
    // REFERENCE_LINK_HOLE_TEXT_END
    // REFERENCE_LINK_HOLE_ID_END
    // FOOTNOTE_HOLE_END
    OPEN_PARENTHESIS, // (
    // LINK_HREF_START
    // IMAGE_HREF_TITLE_START
    CLOSE_PARENTHESIS, // )
    // LINK_HREF_END
    // IMAGE_HREF_TITLE_END
    LINK_LITERAL_START,           // <
    LINK_LITERAL_END,             // >
    IMAGE_TEXT_START,             // ![
    IMAGE_HREF_TITLE_DIVISOR,     // \s+
    REFERENCE_LINK_DATA_ID_START, // ^[
    REFERENCE_LINK_DATA_ID_END,   // ]:
    FOOTNOTE_HOLE_START,          // [^
    FOOTNOTE_DATA_ID_START,       // [^
    FOOTNOTE_DATA_ID_END,         // ]:
} Tokens;

#endif // TOKENS_H