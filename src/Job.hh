<?hh // strict
/**
 * Hphpdoc
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 *
 * @copyright 2016 Appertly
 * @license   Apache-2.0
 */
namespace Hphpdoc;

use FredEmmott\DefinitionFinder\ScannedBase;

/**
 * Contains details of a job run.
 */
class Job
{
    private ImmMap<string,ScannedBase> $tokens;

    /**
     * Creates a new Job.
     *
     * @param $destination - The file path to contain exported pages
     * @param $tokens - All scanned tokens
     */
    public function __construct(private string $destination, \ConstVector<ScannedBase> $tokens)
    {
        $tm = Map{};
        foreach ($tokens as $t) {
            $tm[$t->getName()] = $t;
        }
        $this->tokens = $tm->immutable();
    }

    /**
     * Gets the export file path.
     *
     * @return - The file path to contain exported pages
     */
    public function getDestination(): string
    {
        return $this->destination;
    }

    /**
     * Gets the tokens, keyed by name
     *
     * @return - The scanned tokens, keyed by name
     */
    public function getTokensByName(): ImmMap<string,ScannedBase>
    {
        return $this->tokens;
    }

    /**
     * Gets the tokens.
     *
     * @return - The scanned tokens
     */
    <<__Memoize>>
    public function getTokens(): ImmVector<ScannedBase>
    {
        return $this->tokens->values()->immutable();
    }
}
