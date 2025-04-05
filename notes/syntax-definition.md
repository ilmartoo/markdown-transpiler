# Markdown basic and extended syntax defiition
https://www.markdownguide.org/basic-syntax/
https://www.markdownguide.org/extended-syntax/
## Headers
### Basic definition
```
# Heading level 1
# Heading level 2
## Heading level 3
### Heading level 4
#### Heading level 5
##### Heading level 6
```
### Alternative definition
Any `=` or `-` in the next line by themselves to be a header

```
Heading level 1
===============
Heading level 2
---------------
```
### Ids

```
# Heading {#heading-id}
```
## Newline
A `\n` is like a `<br>`
## Bold

```
I just love **bold text**.  
I just love __bold text__.  
```
## Italic

```
Italicized text is the *cat's meow*.  
Italicized text is the _cat's meow_.  
```
## Bold + Italic

```
This text is ***really important***.  
This text is ___really important___.  
This text is __*really important*__.  
This text is **_really important_**.  
```
## Blockquote

```
> Dorothy followed her through many of the beautiful rooms in her castle.

> Dorothy followed her through many of the beautiful rooms in her castle.                                       
>>> The Witch bade her clean the pots and kettles and sweep the floor and keep the fire fed with wood  
```
## Ordered lists
Any number in any order should be valid, except for the first one, it always has to be a `1.`

```
1. First item
2. Second item
3. Third item
4. Fourth item
```
## Unordered lists
Valid delimiters `-`, `+` or `*`
*Can be mixed, but better if not*

```
- First item
- Second item
- Third item
- Fourth item
```

## Adding Elements in Lists
To add another element in a list while preserving the continuity of the list, indent the element four spaces or one tab, as shown in the following examples

```
* This is the first list item
* Here's the second list item

	I need to add another paragraph below the second list item

* And here's the third list item
```
## Escape character
Removes it from the normal parsing flow, displaying it as is
There is a limited set of possible escapable characters
```
\ 	backslash
` 	backtick (see also escaping backticks in code)
* 	asterisk
_ 	underscore
{ } 	curly braces
[ ] 	brackets
< > 	angle brackets
( ) 	parentheses
# 	pound sign
+ 	plus sign
- 	minus sign (hyphen)
. 	dot
! 	exclamation mark
| 	pipe (see also escaping pipe in tables)
```
## Link

```
[Text to display](link/to/resource)

[Text to display](link/to/resource "This is a link title")

<https://www.quick-link.com>

<fake@email.com>
```
### Link to Header Id

```
[Heading Id link](#header-id)
```
## Images

```
![Alt for the image](link/to/image)

![Alt for the image](link/to/image "This is an image title")
```
## Code

```
`This will be code`

``Double backticks will escape the "`" to display a `code` line where the single backticks can be represented``
```
## Code block
### Basic definition
Indent by 4 spaces or 1 tab all the code lines to create a code block

### Extended definition
Use 3 `` ` `` or `~` to create a code block

```
~~~
Code block with ~
~~~
```

~~~ 
```
Code block with `
```
~~~
## Horizontal rule
Three or more `-`, `*` or `_` in a line by themselves

```
---
***
___
```
## Reference link
First part is the reference
Second part is the reference link
Displays as a normal link, but splits the link in two
### First part

```
[hobbit-hole][1]
[hobbit-hole] [1]
```
### Second part

```
[1]: https://en.wikipedia.org/wiki/Hobbit#Lifestyle
[1]: https://en.wikipedia.org/wiki/Hobbit#Lifestyle "Hobbit lifestyles"
[1]: https://en.wikipedia.org/wiki/Hobbit#Lifestyle 'Hobbit lifestyles'
[1]: https://en.wikipedia.org/wiki/Hobbit#Lifestyle (Hobbit lifestyles)
[1]: <https://en.wikipedia.org/wiki/Hobbit#Lifestyle> "Hobbit lifestyles"
[1]: <https://en.wikipedia.org/wiki/Hobbit#Lifestyle> 'Hobbit lifestyles'
[1]: <https://en.wikipedia.org/wiki/Hobbit#Lifestyle> (Hobbit lifestyles)
```
## Tables

```
| Syntax | Description |
| --- | ----------- |
| Header | Title |
| Paragraph | Text |
```
### Alignment
To align columns, the header column must have a `:` in the side you want to align to, or in both if centered

```
| Syntax      | Description | Test Text     |
| :---        |    :----:   |          ---: |
| Header      | Title       | Here's this   |
| Paragraph   | Text        | And more      |
```

## Footnotes
The footnote id must not contain spaces or tabs

```
This is a text where the footnote will be [^1], here another [^big_note]

[^1]: Footnote
[^big_note]: Here's one with multiple paragraphs and code.

    Indent paragraphs to include them in the footnote.

    `{ my code }`

    Add as many paragraphs as you like.
```

## Strikethrough

```
~~This is bad~~
```
## Task List

```
- [ ] Incomplete task
- [x] Completed task
```
## Subscript
Text between `~` is subscripted

```
H~2~0
```
## Superscript
Text between `^` is supercripted

```
X^2^
```
