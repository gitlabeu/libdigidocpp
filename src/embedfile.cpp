/*
 * libdigidocpp
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc != 4)
		return EXIT_FAILURE;

	FILE *in = fopen(argv[1], "rb");
	FILE *out = fopen(argv[3], "wb");
	if (!in || !out)
		return EXIT_FAILURE;

	fprintf(out, "unsigned char %s[] = {", argv[2]);
	unsigned int ch, i;
	for (i = 0; (ch = fgetc(in)) != EOF; ++i)
	{
		if (i % 12 == 0)
			fprintf(out, "\n");
		fprintf(out, " %#04x,", ch);
	}
	fprintf(out, "};\nunsigned int %s_len = %u;\n", argv[2], i);
	fclose(in);
	fclose(out);

	return EXIT_SUCCESS;
}
